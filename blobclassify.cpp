#include "blobfuns.h"

/**
 *	Blob classificaion between the five available classes in 'BasicBlob.h' (see CLASS typedef). All the input arguments must be 
 *  initialized when using this function.
 *
 * \param frame Input image
 * \param fgmask Foreground/Background segmentation mask (1-channel) 
 * \param pBlobList List to store the blobs found 
 *
 * \return Operation code (negative if not succesfull operation) 
 */
int classifyBlobs(IplImage* frame, IplImage *fgmask, BlobList *pBlobList)
{
	//check input conditions and return -1 if any is not satisfied
	if ( fgmask == NULL || frame == NULL || pBlobList == NULL )
	{
		return -1;
	}

	//required variables for classification
	//for aspect ratio
	float W,H,AR;
	float mean_car,mean_person,std_car,std_person;
	float Pp,Pc;
	
	//classify each blob of the list
	for(int i = 0; i < pBlobList->getBlobNum(); i++) 
	{
		//get the ith blob of the list
		BasicBlob* ith_blob = pBlobList->getBlob(i); 
		H = ith_blob->getHeight();
		W = ith_blob->getWidth();
		
		//calculate the aspect ratio feature
		AR = W/H;
		//Add a function to check size of the blob (add a nodisplay class?);
		//calculate the probability density of the normal distribution (for person)
		mean_person = 0.3645;
		std_person = 0.0621;
		Pp = 1/(std_person*sqrt(2*M_PI))*exp(-(pow(AR-mean_person, 2))/(2*std_person*std_person));
		//Pp = normalPDF(AR, mean_person, std_person);
		//calculate the probability density of the normal distribution (for cars)
		mean_car = 1.8537;
		std_car = 0.6112;
		Pc = 1/(std_car*sqrt(2*M_PI))*exp(-(pow(AR-mean_car, 2))/(2*std_car*std_car));
		//Pc = normalPDF(AR, mean_car, std_car)
		
		//for bags
		//Pb = ...
		
		//classify the blob
		//using simple statistical classifier	
		if (Pp > Pc)
		{
			ith_blob->setlabel(PERSON);
		}else{
			ith_blob->setlabel(CAR);
		}			
		
						
	}
	
	
	//destroy all resources
	//...
	
	//return OK code
	return 1;
}

//float normalPDF(float x, float mean, float std){
//	float result;
//	result = 1/(std*sqrt(2*M_PI))*exp(-(pow(x-mean, 2))/(2*std));
//	return result;	
//}


/**
 *	Draw blobs (and its classes) with different color rectangles on the image 'frame'. All the input arguments must be 
 *  initialized when using this function.
 *
 * \param frame Input image 
 * \param pBlobList List to store the blobs found 
 *
 * \return Image containing the draw blobs. If no blobs have to be painted 
 *  or arguments are wrong, the function returns NULL. The memory of this image 
 * is created inside this function so it has to be released after its use by the 
 * function calling 'paintBlobImage'.
 */
IplImage *paintBlobClasses(IplImage* frame, BlobList *pBlobList)
{
	IplImage *blobImage = NULL;
	if ( frame == NULL || pBlobList == NULL )
	{
		return NULL;
	}	

	//required variables to paint
	float H,W,x,y;
	class classified;
	
			//cvRectangle( frame, cvPoint(10,10), cvPoint(frame->width-10, frame->height-10), white, 2, 8, 0 );

	//paint each blob of the list
	for(int i = 0; i < pBlobList->getBlobNum(); i++) 	
	{	
		//get info about the ithblob
		BasicBlob* ith_blob = pBlobList->getBlob(i); 
		//CAR == ith_blob->getlabel();
		H = ith_blob->getHeight();
		W = ith_blob->getWidth();
		x = ith_blob->getX();
		y = ith_blob->getY();
		
		//get points to describe the rectangle
		//pt1 = cvPoint(x,y);
		//pt2 = cvPoint(W-x,H-y);
		//In white for all class first then specify the color
		CvScalar color = {255};
		cvRectangle( blobImage, cvPoint(x,y), cvPoint(W-x, H-x), color, 2, 8, 0 );
	}

	//destroy all resources (if required)
	//...
	
	//return the image to show
	return blobImage;
}

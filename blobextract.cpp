#include "blobfuns.h"
#include "opencv2/imgproc/imgproc_c.h"

#define MIN_WIDTH 5
#define MIN_HEIGHT 5

/**
 *	Blob extraction from 1-channel image (binary). The extraction is performed based
 *	on the analysis of the connected components. All the input arguments must be 
 *  initialized when using this function.
 *
 * \param frame Input image
 * \param fgmask Foreground/Background segmentation mask (1-channel) 
 * \param pBlobList List to store the blobs found 
 *
 * \return Operation code (negative if not succesfull operation) 
 */
int extractBlobs(Mat frame, Mat fgmask, BlobList *pBlobList)
{	
	//if() ius eñpty or stuff
	//check input conditions and return -1 if any is not satisfied
	//...	
	
	
	//required variables for connected component analysis 
	Point seedPoint;
	Rect * blob_square;
	
	//clear blob list (to fill with this function)
	pBlobList->clear();
			
	//Connected component analysis
	//...
	//change fg segmentation as it should be fg is 0 and bg is 1
	//because flooding cannot go accross non zero
	//...
	//check set to assign to
	//http://docs.opencv.org/modules/core/doc/basic_structures.html#matrixexpressions
	//initialisation of mask needed
	Mat fireMask = Mat(fgmask->width+2,fgmask->height+2);
	Mat H = zeros(1,fgmask->width);
	Mat V = zeros(fgmask->height+2,1);
	fireMask = hconcat(H,fgmask,H);
	fireMask = vconcat(V,fireMask,V);
	
	while(!endImage){
		for (int x=0;x<fireMask->width;x++){
			for (int y=0;y<fireMask->height;y++){
				//TO CHECK IL EST TRES POSSIBLE QUE X Y INVERSES VU QUE OPENCV rfk,5668018+*/16894673894m5m83mç+12.
				if(fireMask.at<uchar>(x,y)==255){
					seedPoint = Point(x,y);		
					//use floating range to compare to the neighbors
					//C++: int floodFill(InputOutputArray image, InputOutputArray mask, seedPoint, newVal, rect, loDiff, upDiff, flags )
					blob_square = new Rect();
					//difference allowed between pixel and neighbors
					Scalar loDiff=Scalar(10);
					Scalar upDiff=Scalar(10);
					//connectivity|val for mask|fixed range|mask only/doesnt change input image
					flags = (4 | (1<<8) | (0<<8) | (1<<8)); 
					//with this function we only search blobs in the pixels segmented as foreground
					flood = floodFill(frame, fgmask, seedPoint, 0, blob_square, loDiff, upDiff, flags);
					//check size of blob using MIN_WIDTH & HEIGHT (valid = true)
					//...
					//TO DO
	
					//include blob in 'pBlobList' if it is valid
					pBlobList->addBlob(blob_square);
				//...
				}
			}
		}
		
	//scan the FG mask to find blob pixels (use one of the two following choices)
	// choice 1 "linear positioning"
	//			for (int i=0;i<fgmask->imageSize;i++)"
	// --- BOUNDING RECT ---
	// choice 2 "2d positioning"
	Mat mask_fire =fgmask;
	for (int x=0;x<fgmask->width;x++)
		for (int y=0;y<fgmask->height;y++)
		{	
		}

	//destroy all resources
	//...
	
	//return OK code
	return 1;
}


/**
 *	Draw blobs with different rectangles on the image 'frame'. All the input arguments must be 
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
IplImage *paintBlobImage(IplImage* frame, BlobList *pBlobList)
{
	IplImage *blobImage=NULL;
	//check input conditions and return NULL if any is not satisfied
	//...		

	//required variables to paint
	//...

	//paint each blob of the list
	for(int i = 0; i < pBlobList->getBlobNum(); i++) 	
	{
	//...	
	}

	//destroy all resources (if required)
	//...
	
	//return the image to show
	return blobImage;
}

#include "blobfuns.h"
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv2/opencv.hpp>

#define MIN_WIDTH 5
#define MIN_HEIGHT 5

using namespace cv;

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
int extractBlobs(IplImage *frameIpl, IplImage *fgmaskIpl, BlobList *pBlobList)
{	
	//if() ius eñpty or stuff
	//check input conditions and return -1 if any is not satisfied
	//...	

	//required variables for connected component analysis 
	Mat frame(frameIpl);
	Mat fgmask(fgmaskIpl);
	Size s=frame.size();
	Rect *blob_square;
	bool endImage;
	//initialisation of mask needed
	
// void copyMakeBorder(InputArray src, OutputArray dst, int top, int bottom, int left, int right, int borderType, const Scalar& value=Scalar() )
	Mat fireMask = Mat(s.width+2,s.height+2,CV_8UC1);
	
	copyMakeBorder(fgmask,fireMask,1,1,1,1,BORDER_CONSTANT,0);
//http://docs.opencv.org/modules/imgproc/doc/filtering.html?highlight=copymakeborder#copymakeborder
//http://docs.opencv.org/doc/tutorials/imgproc/imgtrans/copyMakeBorder/copyMakeBorder.html
	//~ Mat fire1 = Mat::zeros(s.width,s.height+1,CV_8UC1);
	//~ Mat fire2 = Mat(s.width,s.height+2,CV_8UC1);
	//~ Mat fire3 = Mat(s.width+1,s.height+2,CV_8UC1);
	//~ Mat H = Mat::zeros(1,s.width,CV_8UC1);
	//~ Mat V = Mat::zeros(s.height+2,1,CV_8UC1);
	//~ hconcat(H,fgmask,fire1);
	//~ hconcat(fireMask,H,fire2);
	//~ vconcat(V,fireMask,fire3);
	//~ vconcat(fireMask,V,fireMask);
	Size s_mask=fireMask.size();
	std::cout<<s_mask.height<<" " <<s_mask.height<<" "<<std::endl<<s.height<<" "<<s.width<<std::endl;
	//clear blob list (to fill with this function)
	pBlobList->clear();
			
	//Connected component analysis
	//...
	//change fg segmentation as it should be fg is 0 and bg is 1
	//because flooding cannot go accross non zero
	//...
	//check set to assign to
	//http://docs.opencv.org/modules/core/doc/basic_structures.html#matrixexpressions
	
	
	for (int x=0;x<s_mask.width;x++){
		for (int y=0;y<s_mask.height;y++){
			//TO CHECK IL EST TRES POSSIBLE QUE X Y INVERSES VU QUE OPENCV rfk,5668018+*/16894673894m5m83mç+12.
			if(fireMask.at<uchar>(x,y)==255){
						
				//use floating range to compare to the neighbors
				//C++: int floodFill(InputOutputArray image, InputOutputArray mask, seedPoint, newVal, rect, loDiff, upDiff, flags )
				blob_square = new Rect();
				//difference allowed between pixel and neighbors
				int loDiff=10;
				int upDiff=10;
				//usage: connectivity|val for mask|fixed range|mask only<=>doesnt change input image
				int flags = (4 | (1<<8) | (0<<8) | (1<<8)); 
				//with this function we only search blobs in the pixels segmented as foreground
				int flood = floodFill(frame, fgmask, cvPoint(x,y), 0, blob_square, loDiff, upDiff, flags);
				
				assert(flood==0);
				//check size of blob using MIN_WIDTH & HEIGHT (valid = true)
				//...
				//TO DO

				//include blob in 'pBlobList' if it is valid
				//creation of basic blob
				BasicBlob new_blob = BasicBlob();
				new_blob.setX(blob_square->x);
				new_blob.setY(blob_square->y);
				
				pBlobList->addBlob(&new_blob);
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
	for (int x=0;x<s.width;x++)
		for (int y=0;s.height;y++)
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



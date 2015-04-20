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
int extractBlobs(IplImage* frame, IplImage *fgmask, BlobList *pBlobList)
{	
	//check input conditions and return -1 if any is not satisfied
	//...		

	//required variables for connected component analysis 
	//...
	
	//clear blob list (to fill with this function)
	pBlobList->clear();
			
	//Connected component analysis
	//...
		
	//scan the FG mask to find blob pixels (use one of the two following choices)
	// choice 1 "linear positioning"
	//			for (int i=0;i<fgmask->imageSize;i++)"
	
	// choice 2 "2d positioning"
	//			for (int x=0;x<fgmask->width;x++)
	//				for (int y=0;y<fgmask->height;y++)
	{		
		//extract connected component (blob)
		//...
		
		//check size of blob using MIN_WIDTH & HEIGHT (valid = true)
		//...
		
		//include blob in 'pBlobList' if it is valid
		//...
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
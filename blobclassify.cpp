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
int classifyBlobs(Mat frame, Mat fgmask, BlobList *pBlobList)
{
	//check input conditions and return -1 if any is not satisfied
	//...		

	//required variables for classification
	//...
	
	//classify each blob of the list
	for(int i = 0; i < pBlobList->getBlobNum(); i++) 
	{
	//...
	}
	
	//destroy all resources
	//...
	
	//return OK code
	return 1;
}


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
Mat paintBlobClasses(Mat frame, BlobList *pBlobList)
{
	Mat blobImage;
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

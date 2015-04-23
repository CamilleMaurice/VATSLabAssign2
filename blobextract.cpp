#include "blobfuns.h"
#include "BasicBlob.h"
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv2/opencv.hpp>
//#include <iostream>
#define MIN_WIDTH 15
#define MIN_HEIGHT 15

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
	
	//required variables for connected component analysis 
	Mat frame(frameIpl);
	Mat fgmask(fgmaskIpl);
	Size s=frame.size();
	//initialisation of mask
	Mat fireMask(s.width+2,s.height+2,CV_8UC1);
	copyMakeBorder(fgmask,fireMask,1,1,1,1,BORDER_CONSTANT,0);
	Size s_mask=fireMask.size();

	//clear blob list (to fill with this function)
	pBlobList->clear();

	//change fg segmentation as it should be fg is 0 and bg is 1
	//because flooding cannot go accross non zero

	//check set to assign to

	//http://docs.opencv.org/modules/core/doc/basic_structures.html#matrixexpressions
	
		//adapting the FG mask from input to fit the function floodfill
	for (int x=1;x<s_mask.width-1;x++){
		for (int y=1;y<s_mask.height-1;y++){
			//~ if(fireMask.at<uchar>(y,x)==255)
				//~ printf("%u - ",fireMask.at<uchar>(y,x));
			switch(fireMask.at<uchar>(y,x)){
				case 0:
					fireMask.at<uchar>(y,x)=1;
					break;
				case 127:
					fireMask.at<uchar>(y,x)=1;
					break;
				case 255:
					fireMask.at<uchar>(y,x)=0;
					break;
				default:
					printf("strange value in mask: %u at pix(%d,%d)\n",fireMask.at<uchar>(y,x),x,y);
			};
					break;		
			//~ if(fireMask.at<uchar>(y,x)!=0)
				//~ printf("%u \n",fireMask.at<uchar>(y,x));
		}
	}
	imshow("fireMask",fireMask);
	waitKey(0);

	
	for (int x=0;x<s.width;x++){
		for (int y=0;y<s.height;y++){
			if(fireMask.at<uchar>(y,x)==0){						
				//std::cout<<"seed Point: "<<x<<" "<<y<<" - ";
				Rect *blob_square = new Rect();
				//difference allowed between pixel and neighbors
				int loDiff=10;
				int upDiff=10;
				//usage: connectivity|val for mask|fixed range|mask only<=>doesnt change input image
				int flags = (8 | (1<<8) | (0<<8) | (1<<8)); 
				//with this function we only search blobs in the pixels segmented as foreground
				int flood = floodFill(frame, fireMask, cvPoint(x,y), 0, blob_square, loDiff, upDiff, flags);
				//if(flood!=1)
				//	std::cerr<<"flood fill returns "<<flood;
				//~ std::cout<<blob_square->width<<" "<<blob_square->height<<std::endl;
				//check size of blob using MIN_WIDTH & HEIGHT (valid = true)
				if(blob_square->width>= MIN_WIDTH && blob_square->height >= MIN_HEIGHT){
					//include blob in 'pBlobList' if it is valid
					//creation of basic blob
					BasicBlob * new_blob = new BasicBlob();
					new_blob->setX((blob_square->x));
					new_blob->setY((blob_square->y));
					
					pBlobList->addBlob(new_blob);
				}
			//...
			}
		}
	}
	
		
	//scan the FG mask to find blob pixels (use one of the two following choices)
	// choice 1 "linear positioning"
	//			for (int i=0;i<fgmask->imageSize;i++)"
	// --- BOUNDING RECT ---
	// choice 2 "2d positioning"
	

	//destroy all resources
	//~ //...
	if(pBlobList->getBlobNum()>0)
		std::cout<<pBlobList->getBlobNum()<<" blobs created"<<std::endl;
	//return OK code
	return EXIT_SUCCESS;
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
	Mat or_frame(frame);
	Mat blob_frame = or_frame.clone();
	Size s=or_frame.size();
	//check input conditions and return NULL if any is not satisfied
	//...		

	//required variables to paint
	//...

	//paint each blob of the list
	for(int b = 0; b < pBlobList->getBlobNum(); b++) 	
	{
		//~ BasicBloc *blob =  pBlobList->getBlob(b);
		//~ int x = blob.getX();
		//~ int y = blob.getY();
		//~ int w = blob.getWidth();
		//~ int h = blob.getHeight();
		//~ CvScalar color = {0,255,0};
		//~ cvRectangle(frame, cvPoint(x,y), cvPoint(x+w, y+h), color, 2, 8, 0 );
	}

	//destroy all resources (if required)
	//...
	
	//return the image to show
	return blobImage;
}



//file description
/**
 * \file main.cpp 
 * \author Juan Carlos San Miguel
 * \date 09/03/2013
 * \brief Scheme for lab sessions of VATS (I2TIC Master - EPS (UAM)
 * \version 1.0\n 
 *
 */

//standard and OpenCV functions
#include <stdio.h>
#include <opencv2/opencv.hpp>

//include for blob-related functions
#include "blobfuns.h" 

#define INPUT_VIDEO	"mh.mpg"

using namespace cv;
using namespace std;

int going_on;

int main()
{	
	going_on = 1;
	// Required variables for the program
	//CvCapture* capture=NULL;
	Mat frame, fg, bg; //images for background subtraction	
	Mat fgcounter, sfg; //images for stationary foreground analysis (counter and static fg mask)
	Mat outblobs, outlabels; //output images for blob extraction and blob labels
	
	//CvVideoWriter *videowriter;
	
	double start=0,end=0,total=0;	
	int i = 0;
	
	//only used to write on video VATS in a rectangle
	//cvScalar white = {255};
	//CvFont font;
	//char buf[100];
	
	//read video file & first frame
	VideoCapture cap(INPUT_VIDEO);

	if(!cap.isOpened()) {// check if we succeeded
		printf("Bad Video File\n");
		return -1;}
	
		cap>>frame;
	
	//image initialization (counters, auxiliar images,...)
	//...
		
	//module initialization (background subtraction, bloblist,...)
	//...
	BlobList *blobList = new BlobList();
		
	//create output windows	
	//...

	// I dont know yet how to create a video using c++/opencv 
	//create output writer
	//videowriter = cvCreateVideoWriter("result.mpg", CV_FOURCC('P','I','M','1'), 25, cvGetSize(frame), 1 );	
	//cvInitFont( &font, CV_FONT_HERSHEY_DUPLEX, 0.8, 0.8, 0, 2, 8 );
	
	do
	{
		i++;
		//cvGetTickCount or getTickCount does not exist on linux
		//start =((double)cvGetTickCount()/(cvGetTickFrequency()*1000.) );

		//background subtraction (final foreground mask must be placed in 'fg' variable)
		//...

		//blob extraction
		extractBlobs(frame, fg, blobList); //blob extraction
		outblobs = paintBlobImage(frame, blobList);//paint blobs

		//blob classification
		classifyBlobs(frame, fg, blobList); //classify blobs
		outlabels = paintBlobClasses(frame, blobList);//paint classification blobs
		
		//stationary blob detection
		//detectStationaryForeground(frame, fg, fgcounter, sfg);

		// Drawing and text functions for frame
		//cvRectangle( frame, cvPoint(10,10), cvPoint(frame->width-10, frame->height-10), white, 2, 8, 0 );
		//sprintf(buf,"VATS");
		//cvPutText(frame, buf, cvPoint(20,frame->height-30), &font, white );

		//show results visually
		//...
	
		//cvGetTickCount or getTickCount does not exist on linux
		//end = ((double)cvGetTickCount()/(cvGetTickFrequency()*1000.) );
		total=total + end-start;

		printf("Processing frame %d --> %.3g ms\n", i,end-start);		
		waitKey( 2 );

		//write frame result to video
		//cvWriteFrame( videowriter, outblobs );		
		
		//release memory of temporal images
		//Use of Mat 
		//cvReleaseImage( &outblobs );
		//cvReleaseImage( &outlabels );
		if(waitKey(30) >= 0)
			break;
			
	} while (going_on == 1);
		
	//destroy all resources
	delete blobList;

	return 1;
}

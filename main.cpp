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
#include <iostream>
#include <sstream>
//include for blob-related functions
#include "blobfuns.h" 

#define INPUT_VIDEO	"mh.mpg"

using namespace cv;
using namespace std;

int main()
{	
	// Required variables for the program
	CvCapture* capture=NULL;
	IplImage *frame=NULL, *fg=NULL, *bg=NULL; //images for background subtraction	
	IplImage *fgcounter=NULL, *sfg=NULL; //images for stationary foreground analysis (counter and static fg mask)
	IplImage *outblobs=NULL, *outlabels=NULL; //output images for blob extraction and blob labels
	
	Mat fgM, bgM;
	Mat fgcounterM,sfgM;
	Mat outblobsM, outlabelsM;
	
	CvVideoWriter *videowriter;
	
	//BG subtractor init
	cv::BackgroundSubtractorMOG2 subtractor;
    subtractor.set("nmixtures", 3);
    subtractor.set("detectShadows", true);
    //subtractor.nmixtures = 3;
    //subtractor.bShadowDetection = false;
	
	double start=0,end=0,total=0;	
	int i = 0;
	CvScalar white = {255};

	CvFont font;
	char buf[100];
	
	//read video file & first frame
	if(!(capture = cvCaptureFromFile(INPUT_VIDEO)))
	{
		printf("Bad Video File\n");
		return -1;
	}
	
	frame = cvQueryFrame( capture );
	
	//image initialization (counters, auxiliar images,...)
	//...
		
	//module initialization (background subtraction, bloblist,...)
	//...
	BlobList *blobList = new BlobList();
		
	//create output windows	
	namedWindow("frameM");
	namedWindow("Foreground");

	//create output writer
	videowriter = cvCreateVideoWriter("result.mpg", CV_FOURCC('P','I','M','1'), 25, cvGetSize(frame), 1 );	
	cvInitFont( &font, CV_FONT_HERSHEY_DUPLEX, 0.8, 0.8, 0, 2, 8 );
	
	do
	{
		i++;
		start =((double)cvGetTickCount()/(cvGetTickFrequency()*1000.) );

		//background subtraction (final foreground mask must be placed in 'fg' variable)
		//...
		
		Mat frameM(frame);
		
		subtractor.operator ()(frameM,fgM);
        subtractor.getBackgroundImage(bgM);
		
		imshow("frameM", frameM);
	    imshow("Foreground", fgM);
	    
	    //convert Mat fg to IplImage
	    //Maybe better to change the argument of extractBlobs so it accepts Mat and
	    //convert if needed inside the function
		 
		 IplImage fgtmp = fgM; 
		 IplImage* fg = &fgtmp;
		
		
		//blob extraction
		//extractBlobs(frame, fg, blobList); //blob extraction
		//outblobs = paintBlobImage(frame, blobList);//paint blobs

		//blob classification
		//classifyBlobs(frame, fg, blobList); //classify blobs
		//outlabels = paintBlobClasses(frame, blobList);//paint classification blobs
		
		//stationary blob detection
		//detectStationaryForeground(frame, fg, fgcounter, sfg);

		// Drawing and text functions for frame
		
		cvRectangle( frame, cvPoint(10,10), cvPoint(frame->width-10, frame->height-10), white, 2, 8, 0 );
		
		sprintf(buf,"VATS");
		
		//cvPutText(frame, buf, cvPoint(20,frame->height-30), &font, white );
		
		//show results visually
		//...
	
		end = ((double)cvGetTickCount()/(cvGetTickFrequency()*1000.) );
		
		total=total + end-start;

		printf("Processing frame %d --> %.3g ms\n", i,end-start);
			
		cvWaitKey( 2 );
		

		//write frame result to video
		//cvWriteFrame( videowriter, outblobs );		
		
		//release memory of temporal images
		//cvReleaseImage( &outblobs );
		//cvReleaseImage( &outlabels );

	} while (frame=cvQueryFrame( capture ));
		
	//destroy all resources
	//delete blobList;

	return 1;
}

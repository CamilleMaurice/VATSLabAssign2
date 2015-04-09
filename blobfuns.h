#ifndef BLOBFUNS_H_INCLUDE
#define BLOBFUNS_H_INCLUDE

#include "BasicBlob.h"
#include "BlobList.h"

//blob extraction functions (included in 'blobextrac.cpp')
int extractBlobs(Mat frame, Mat fgmask, BlobList *pBlobList);
Mat paintBlobImage(Mat frame, BlobList *pBlobList);

//blob classification functions (included in 'blobclassify.cpp')
int classifyBlobs(Mat frame, Mat fgmask, BlobList *pBlobList);
Mat paintBlobClasses(Mat frame, BlobList *pBlobList);

//stationary blob detection functions (included in 'blobstationary.cpp')
int detectStationaryForeground(Mat frame, Mat fgmask, Mat fgmask_counter, Mat sfgmask);

#endif

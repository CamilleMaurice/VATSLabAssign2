#include "blobfuns.h"

#define FPS 25 //framerate of the input video
#define MIN_SECS 10.0 //minimum number of seconds to consider a foreground pixel as stationary

#define C_COST 1 //increment cost for stationary detection
#define D_COST 5 //penalization cost for stationary detection


/**
 *	Function to detect stationary foreground based on accumulator techniques. All the input arguments must be 
 *  initialized prior using this function.
 *
 * \param frame Input image
 * \param fgmask Foreground/Background segmentation mask (1-channel, uint8)  
 * \param fgmask_counter counter for stationary pixels (1-channel, float) 
  obtained in the analysis of the previous frame (to be updated in this function)
 * \param sfgmask Foregroung segmentation mask (1-channel, uint8)  with the stationary pixels
 *
 * \return Operation code (negative if not succesfull operation) 
 */
int detectStationaryForeground(Mat frame, Mat fgmask, Mat fgmask_counter, Mat sfgmask)
{
	//check input validity and return -1 if any is not valid
	//...
	
	//num frames to static
	int numframes2static = (int)(FPS * MIN_SECS);

	//operate with fgmask to update fgmask_counter
	//...

	//operate with fgmask_counter to update sfgmask
	//...
	
	return 1;
}

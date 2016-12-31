#include "Pipeline.h"
/**
* Initializes a Pipeline.
*/
Pipeline::Pipeline() {
}
/**
* Runs an iteration of the Pipeline and updates outputs.
*
* Sources need to be set before calling this method. 
*
*/
void Pipeline::Process(){
	//Step RGB_Threshold0:
	//input
	Mat rgbThresholdInput = source0;
	double rgbThresholdRed[] = {0.0, 77.49575551782682};
	double rgbThresholdGreen[] = {0.0, 153.25976230899832};
	double rgbThresholdBlue[] = {0.0, 47.190152801358224};
//	rgbThreshold(rgbThresholdInput, rgbThresholdRed, rgbThresholdGreen, rgbThresholdBlue, this->rgbThresholdOutput);
	rgbThreshold(rgbThresholdInput, rgbThresholdRed, rgbThresholdGreen, rgbThresholdBlue, rgbThresholdInput);
	//Step Find_Contours0:
	//input
//	Mat findContoursInput = rgbThresholdOutput;
	Mat findContoursInput = rgbThresholdInput;
	bool findContoursExternalOnly = false;
	findContours(findContoursInput, findContoursExternalOnly, this->findContoursOutput);
}

/**
 * This method is a generated setter for source0.
 * @param source the Mat to set
 */
void Pipeline::setsource0(Mat &source0){
//	source0.copyTo(this->source0);
	this->source0 = source0;
}
/**
 * This method is a generated getter for the output of a RGB_Threshold.
 * @return Mat output from RGB_Threshold.
 */
Mat* Pipeline::getrgbThresholdOutput(){
	return &(this->rgbThresholdOutput);
}
/**
 * This method is a generated getter for the output of a Find_Contours.
 * @return ContoursReport output from Find_Contours.
 */
vector<vector<cv::Point> >* Pipeline::getfindContoursOutput(){
	return &(this->findContoursOutput);
}
	/**
	 * Segment an image based on color ranges.
	 *
	 * @param input The image on which to perform the RGB threshold.
	 * @param red The min and max red.
	 * @param green The min and max green.
	 * @param blue The min and max blue.
	 * @param output The image in which to store the output.
	 */
	void Pipeline::rgbThreshold(Mat &input, double red[], double green[], double blue[], Mat &output) {
		cvtColor(input, output, COLOR_BGR2RGB);
		inRange(output, Scalar(red[0], green[0], blue[0]), Scalar(red[1], green[1], blue[1]), output);
	}
	/**
	 * Finds contours in an image.
	 *
	 * @param input The image to find contours in.
	 * @param externalOnly if only external contours are to be found.
	 * @param contours vector of contours to put contours in.
	 */
	void Pipeline::findContours(Mat &input, bool externalOnly, vector<vector<cv::Point> > &contours) {
		vector<Vec4i> hierarchy;
		contours.clear();
		int mode = externalOnly ? RETR_EXTERNAL : RETR_LIST;
		int method = CHAIN_APPROX_SIMPLE;
//		findContours(input, contours, hierarchy, mode, method);
		cv::findContours(input, contours, hierarchy, mode, method);
	}


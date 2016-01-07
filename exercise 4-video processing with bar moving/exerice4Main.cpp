#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
#include <string>

//global section 
int g_sllider_position = 0;//this save the postion of the slider 
int g_run = 1;			  //if positive number (bigger than 0 ) save the numbers of frame to show until stop , if it equal to 0 it mean that the video need to stop and negative number mean that it in run mode
int g_dontSet = 0;		  //allow us to update trackbar position without triggering single state mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *)
{
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
	if (!g_dontSet)
		g_run = 1;
	
	g_dontSet = 0;
}

int main(int argc, char ** argv)
{
	int videoSpeed = 33;

	std::string fileName;
	std::cout << "please enter video file\n";
	std::cin >> fileName;

	cv::namedWindow("example4", cv::WINDOW_AUTOSIZE);
	
	//need to check file name 
	g_cap.open(fileName);
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	std::cout << "codeo has " << frames << "frames of dimension " << tmpw << ", " << tmph << std::endl;
	
	//first parameter is the name of the trackbar second is the window name therad is the sllider position four is the number 
	//of frames and the last one is calback function ( after the createtrackbar will be caled it will call to the callback function ) in case that no need callbackfunction put null
	cv::createTrackbar("position", "example4", &g_sllider_position, frames, onTrackbarSlide);

	cv::Mat frame;
	while (true)
	{
		if (g_run != 0)
		{
			g_cap >> frame;
			if (!frame.data)
				break;

			int currentPosition = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
			g_dontSet = 1;
			cv::setTrackbarPos("position", "example4", currentPosition);
			cv::imshow("example4", frame);
			g_run -= 1;
		}

		char c = (char)cv::waitKey(videoSpeed);
		if (c == 's') //sngel step
		{
			g_run = 1;
			std::cout << "singel mode\n";
			std::cout << "enter speed video\n";
			std::cin >> videoSpeed;
		}
		if (c == 'r')//run mode
		{
			g_run = -1;
			std::cout << "run mode\n";
		}

		if (c == 27)
			break;



	}
	
return(EXIT_SUCCESS);


}
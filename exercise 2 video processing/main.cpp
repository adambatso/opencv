#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
	std::string filePath;
	std::cout << "enter video path to play \n";
	std::cin >> filePath;

	cv::namedWindow("exercise2", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(filePath);
	cv::Mat frame;


	while (1)
	{
		cap >> frame;
		if (!frame.data) break;
		cv::imshow("exercise2", frame);
		if (cv::waitKey(200) >= 0) break;

	}
	return EXIT_SUCCESS;
}

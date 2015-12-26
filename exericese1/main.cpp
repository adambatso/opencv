#include "opencv2/highgui/highgui.hpp"
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
	std::string fileName;
	std::cout<< "please enter file path\n";
	std::cin >> fileName;
	//TODO need to check the filepath with regular exeption 
	cv::Mat image = cv::imread(fileName,-1);

	if (image.empty())
	{
		return EXIT_FAILURE;//sdasdasdas
	}

	cv::namedWindow("example1", cv::WINDOW_AUTOSIZE);
	cv::imshow("example1", image);
	cv::waitKey(0);
	cv::destroyWindow("example1");
	return EXIT_SUCCESS;

	//asdasdsadasdsakld
}
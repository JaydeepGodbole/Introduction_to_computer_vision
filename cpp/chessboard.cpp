#include<iostream>
//#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;

int main(int argc, char **argv)
{
	Mat image1;
	image1 = imread( argv[1] , 1);
	Mat image2(2*image1.rows, 2*image1.cols, CV_8UC3 ,Scalar(255,255,255));
	int i,j;;
	for(i=0; i<image1.rows; i++)
	{
		for (j=0; j<image1.cols ; j++)
		{
			image2.at<Vec3b>(i,j) = image1.at<Vec3b>(image1.rows - i,image1.cols - j);
			image2.at<Vec3b>(i + image1.rows,j) = image1.at<Vec3b>(i,image1.cols - j);
			image2.at<Vec3b>(i,j + image1.cols) = image1.at<Vec3b>(image1.rows - i,j);
			image2.at<Vec3b>(i + image1.rows,j + image1.cols) = image1.at<Vec3b>(i,j);	
		}
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display image", image2);
	waitKey(0);
}
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img;


/*void update_img(int t,void *c)
{
	Mat img_gb(img.rows,img.cols, CV_8UC1, Scalar(0));
	img_gb = img;
    GaussianBlur( img, img_gb , Size(3,3), float(t), float(t), BORDER_DEFAULT );
    imshow("Blurred", img_gb);
    waitKey(500);
}
*/
int main(int argc , char **argv)
{
	int t = 1;
	img = imread(argv[1], 1);
	cvtColor( img, img, COLOR_BGR2GRAY );
	//img_gb = img;
	//GaussianBlur( img, img_gb, Size(3,3), 7, 7, BORDER_DEFAULT);
	Mat img_gb(img.rows,img.cols, CV_8UC1, Scalar(0));
    GaussianBlur( img, img_gb , Size(3,3), 1, 1, BORDER_DEFAULT );
	namedWindow("Original", WINDOW_NORMAL);
	namedWindow("Blurred", WINDOW_NORMAL);
	namedWindow("Xgrad",WINDOW_NORMAL);
	namedWindow("Ygrad",WINDOW_NORMAL);
	Mat xgrad(img.rows,img.cols, CV_8UC1, Scalar(0));
	Mat ygrad(img.rows,img.cols, CV_8UC1, Scalar(0));
	Scharr( img_gb, xgrad, -1/CV_16S/CV_32F/CV_64F, 1, 0, 1, 0, BORDER_DEFAULT );
	Sobel( img_gb, ygrad, -1/CV_16S/CV_32F/CV_64F, 1, 0, 3, 1, 0, BORDER_DEFAULT );
	//Scharr( img_gb, ygrad, -1/CV_16S/CV_32F/CV_64F, 0, 1, 1, 0, BORDER_DEFAULT );
	//createTrackbar("b", "Blurred", &t, 7, update_img);
	imshow("Xgrad", xgrad);
	imshow("Ygrad", ygrad);
	imshow("Original", img);
	imshow("Blurred", img_gb);

	waitKey(0);
}
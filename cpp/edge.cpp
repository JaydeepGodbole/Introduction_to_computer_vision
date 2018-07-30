//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/core/core.hpp"
#include<opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat img;

int main(int argc , char **argv)
{
	int t = 1;
	img = imread(argv[1], 1);
	cvtColor( img, img, COLOR_BGR2GRAY );
	//img_gb = img;
	//GaussianBlur( img, img_gb, Size(3,3), 7, 7, BORDER_DEFAULT);
	Mat img_gb(img.rows,img.cols, CV_8UC1, Scalar(0));
	Mat edge_img(img.rows,img.cols, CV_8UC1, Scalar(0));
    GaussianBlur( img, img_gb , Size(3,3), 1, 1, BORDER_DEFAULT );
    cout << img.rows << endl;
    cout << img.cols << endl;
	namedWindow("Original", WINDOW_NORMAL);
	namedWindow("Blurred", WINDOW_NORMAL);
	namedWindow("Edges", WINDOW_NORMAL);
	Canny(img_gb, edge_img, 230, 100, 3, 1);
	//createTrackbar("b", "Blurred", &t, 7, update_img);
	imshow("Original", img);
	imshow("Blurred", img_gb);
	imshow("Edges", edge_img);

	waitKey(0);
}
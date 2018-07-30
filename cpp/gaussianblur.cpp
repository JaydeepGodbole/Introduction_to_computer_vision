#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img;

Mat gb(Mat img, int a)
{
	Size ksize;
	ksize.width = a;
	ksize.height = a;
	Mat filtered(img.rows, img.cols, CV_8UC3, Scalar(0,0,0));
	GaussianBlur(img, filtered, ksize, 1, 1, BORDER_DEFAULT );
	return filtered; 
}

void update_img(int t)
{
    int i,j,a,b;
    a=img.rows;
    b=img.cols;
    Mat img1(a,b,CV_8UC3,Scalar(0,0,0));
    img1 = gb(img, t);
    //img1 = img*(t/100);
    imshow("My_Window",img1);
    waitKey(1000);
}

int main(int argc, char **argv)
{
	int sigma = 1,t;
	img = imread(argv[1], 1);
	while(1)
	{
	cin >> t;
	update_img(t);
	}
	waitKey(0);
}
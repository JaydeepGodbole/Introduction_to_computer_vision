#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

Mat img;

const float pi = 3.14159;

Mat drawline (Mat img, int theta, float d)
{
	Mat returnimg(img.rows, img.cols, CV_8UC1, Scalar(0));
	int i,j;
	for(i=0;i<img.rows;i++)
	{	
		if(((d + i*sin(theta*pi/180.0))/cos(theta*pi/180.0) > 0) && ((d + i*sin(theta*pi/180.0))/cos(theta*pi/180.0) < img.cols+1))
		{
			j = int((d + i*sin(theta*pi/180.0))/cos(theta*pi/180.0));
			returnimg.at<uchar>(i,j) = 255;
		}
	}
	return returnimg;

}

int main(int argc , char **argv)
{
	int t = 1;
	img = imread(argv[1], 1);
	cvtColor( img, img, COLOR_BGR2GRAY );
	Mat img_gb(img.rows,img.cols, CV_8UC1, Scalar(0));
	Mat edge_img(img.rows,img.cols, CV_8UC1, Scalar(0));
	Mat line_img(img.rows, img.cols, CV_8UC3,Scalar(0,0,0));
    GaussianBlur( img, img_gb , Size(3,3), 0.5, 0.5, BORDER_DEFAULT );
	namedWindow("Original", WINDOW_NORMAL);
	namedWindow("Blurred", WINDOW_NORMAL);
	namedWindow("Edges", WINDOW_NORMAL);
	namedWindow("Line", WINDOW_NORMAL);
	Canny(img_gb, edge_img, 180, 100, 3, 1);
	cvtColor(edge_img, line_img, COLOR_GRAY2BGR);
	vector<Vec4i> lines;
	HoughLinesP(edge_img, lines, 0.1, CV_PI/180, 150, 50, 10 );
	for(size_t t=0; t<lines.size(); t++)
	{
		line(line_img, Point(lines[t][0], lines[t][1]), Point(lines[t][2], lines[t][3]), Scalar(0,0,255), 3);
	}
	/*vector<Vec2f> lines;
	HoughLines(edge_img, lines, 0.1, CV_PI/180, 150, 50, 10 );
	for(size_t t=0; t<lines.size(); t++)
	{
		line(line_img, lines[t][0], lines[t][1], Scalar(0,0,255), 3);
	}*/

	imshow("Original", img);
	imshow("Blurred", img_gb);
	imshow("Edges", edge_img);
	imshow("Line", line_img);

	waitKey(0);
}

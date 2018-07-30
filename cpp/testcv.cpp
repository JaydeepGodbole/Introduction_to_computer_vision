#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;
#include  <math.h>
/*
float minvalue(Mat img)
{
	float min = img.at<uchar>(0,0);
	int i,j,mini,minj;
	mini =0; minj = 0;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j) < min)
			{
				min = img.at<uchar>(i,j);
				mini = i;
				minj = j;
			}

		}
	}
	cout << "The min is at ("<< mini << "," << minj << ")" << endl;
	return min;
}

int maxvalue(Mat img)
{
	int max = img.at<uchar>(0,0);
	int i,j,maxi,maxj;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j) > max)
			{
				max = img.at<uchar>(i,j);
				maxi = i;
				maxj = j;
			}
		}
	}
	cout << "The max is at ("<< maxi << "," << maxj << ")" << endl;
	return max;
}


/*float mapped(float val, float min, float max)
{
	return  (val - min)/(val - max)*255;
}

Mat edge(Mat img, int threshold)
{
	
}
Mat img;
void update_img(int t,void *c)
{
    int i,j,a,b;
    a=img.rows;
    b=img.cols;
    Mat img1(a,b,CV_8UC1,Scalar(0));
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
        	if(img.at<uchar>(i,j) > t) 
        	img1.at<uchar>(i,j) = 0;
        	else img1.at<uchar>(i,j) = 255;    
        }
    }    
    imshow("image",img1);
    waitKey(500);

}
*/
int main()
{
	cout << asin(-0.8);
}
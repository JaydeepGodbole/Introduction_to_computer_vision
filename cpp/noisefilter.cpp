#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int median(int *a, int n)
{
    int i,j,min,t;
    for(i=0; i<n; i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;  
            } 
        }
    }
    return a[(n-1)/2];
}


Mat medianfilter(Mat img)
{
    int r = img.rows;
    int c = img.cols;
    int i,j,u,v;
    int a[9];
    Mat fimg(img.rows,img.cols,CV_8UC1,Scalar(0));
    for(i=0;i<r;i++)       
    {
        for(j=0;j<c;j++)
        {
            if((i==0) || (i==r-1) || (j==0) || (j==c-1))
            {
                fimg.at<uchar>(i,j) = 0;
            }
            else
            {
            for(u=0;u<3;u++)
            {
                for(v=0;v<3;v++)
                {
                  a[3*u+v] = img.at<uchar>(i+u-1,j+v-1);
                }
            }
            fimg.at<uchar>(i,j) = median(a, 9);
            }
        }
    }

    return fimg;
}

/*int notequal(Mat a, Mat b)
{
    int i,j;
    if((a.rows != b.rows)||(a.cols)||(b.cols)) return 1;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.cols;j++)
        {
            if(a.at<uchar>(i,j) != b.at<uchar>(i,j))
                return 1;
        }
    }
    return 0;
}
*/

int main()
{
    namedWindow("My_Window",WINDOW_NORMAL);
    namedWindow("My_Window1",WINDOW_NORMAL);
    namedWindow("My_Window2",WINDOW_NORMAL);
    Mat img = imread("sandpnoise.png",0);
    int i;
    Mat fimg1(img.rows,img.cols,CV_8UC1,Scalar(0));
    Mat fimg2(img.rows,img.cols,CV_8UC1,Scalar(0));
    fimg1 = medianfilter(img);
    fimg2 = medianfilter(fimg1);
    for(i=0;i<100;i++)
    {
        fimg1 = medianfilter(fimg1);
        fimg2 = medianfilter(fimg2);
    }
    imshow("My_Window",img);
    imshow("My_Window1",fimg1);
    imshow("My_Window2",fimg2);
    waitKey(0);
}
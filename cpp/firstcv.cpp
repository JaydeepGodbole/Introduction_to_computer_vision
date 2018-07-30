#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img;
void update_imgb(int t,void *c)
{
    int i,j,a,b;
    a=img.rows;
    b=img.cols;
    Mat img1(a,b,CV_8UC1,Scalar(0));
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if((img.at<Vec3b>(i,j)[0] - img.at<Vec3b>(i,j)[1] > t) && (img.at<Vec3b>(i,j)[0] - img.at<Vec3b>(i,j)[2]))
                img1.at<uchar>(i,j) = 255;
            else if(img.at<Vec3b>(i,j)[0] <= t)
            img1.at<uchar>(i,j) = 0;
        }    
    }
    imshow("My_Blue",img1);
    waitKey(500);
    
}

void update_imgg(int t,void *c)
{
    int i,j,a,b;
    a=img.rows;
    b=img.cols;
    Mat img1(a,b,CV_8UC1,Scalar(0));
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if((img.at<Vec3b>(i,j)[1] - img.at<Vec3b>(i,j)[0] > t) && (img.at<Vec3b>(i,j)[1] - img.at<Vec3b>(i,j)[2]))
                img1.at<uchar>(i,j) = 255;
            else if(img.at<Vec3b>(i,j)[1] <= t)
            img1.at<uchar>(i,j) = 0;
        }    
    }
    imshow("My_Green",img1);
    waitKey(500);
    
}
void update_imgr(int t,void *c)
{
    int i,j,a,b;
    a=img.rows;
    b=img.cols;
    Mat img1(a,b,CV_8UC1,Scalar(0));
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if((img.at<Vec3b>(i,j)[2] - img.at<Vec3b>(i,j)[0] > t) && (img.at<Vec3b>(i,j)[2] - img.at<Vec3b>(i,j)[1]))
                img1.at<uchar>(i,j) = 255;
            else if(img.at<Vec3b>(i,j)[2] <= t)
            img1.at<uchar>(i,j) = 0;
        }    
    }
    imshow("My_Red",img1);
    waitKey(500);

}   
int main()
{
    namedWindow("My_Blue",WINDOW_NORMAL);
    namedWindow("My_Green",WINDOW_NORMAL);
    namedWindow("My_Red",WINDOW_NORMAL);
    namedWindow("My_original",WINDOW_NORMAL);
    int th1=127,th2 = 127, th3 = 127;
    img=imread("fruits.jpeg",1);
    createTrackbar("b","My_Blue",&th1,255,update_imgb);
    createTrackbar("g","My_Green",&th2,255,update_imgg);
    createTrackbar("r","My_Red",&th3,255,update_imgr);
    imshow("My_original",img);
    waitKey(0);

}
#include <opencv2/opencv.hpp>
//#include<cstdio>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg"),gray,hsv;
	//三通道顺序，B,G,R
	cvtColor(img, gray, COLOR_BGR2GRAY);
	cvtColor(img, hsv, COLOR_BGR2HSV);
	imshow("HSV", hsv);//H(颜色) 0~180 S(颜色/饱和度),V(亮度) 0-255
	imshow("GRAY", gray);
	imwrite("HSV.jpg", hsv);
	imwrite("gray.jpg", gray);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
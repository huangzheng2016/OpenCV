#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	imshow("hz2016", img);
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	Mat ret;
	inRange(hsv, Scalar(0,0,221), Scalar(180,30,255), ret);
	//[LOWERB，UPPERB]之间，注意集合的开闭。如果结果为是，那么在DST相应像素位置填上255，反之则是0。
	imshow("Ret", ret);
	Mat redback = Mat::zeros(img.size(), img.type());
	redback = Scalar(40, 40, 200);//准备填入红色低
	bitwise_not(ret, ret);//背景取反
	img.copyTo(redback, ret);//只为不为0的才会被迁移，
	//image.copyTo(imageROI，mask),作用是把mask和image重叠以后把mask中像素值为0（black）的点对应的image中的点变为透明，而保留其他点。
	//就是原图img和redback重合，然后mask中是黑色的，redback为透明
	imshow("RetredBack", redback);
	waitKey(0);
	return 0;
}
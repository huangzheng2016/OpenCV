#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat a = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat b = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(a, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8);
	rectangle(b,Rect(150,150, 80, 80), Scalar(0, 255, 255), -1, LINE_8);
	//Rect(x,y,high,weight),x,y为左上角坐标 thickness--1(线宽) <0填充矩形，>0绘制边长thickness矩形
	//LINE4,8周围多少个像素提供支持（透明通道反锯齿），LINEAA全部平均（计算很慢）
	imshow("A", a);
	imshow("B", b);
	Mat c;
	//bitwise_and(a, b, c);//像素位和操作
	//bitwise_not(a, b, c);
	//bitwise_not(a, b, c);
	//bitwise_xor(a, b, c);
	c = ~(a&b);//!(a and b)
	imshow("C", c);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
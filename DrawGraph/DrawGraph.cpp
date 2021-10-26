#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main() {
	Mat img = imread("hz2016.png");
	Mat draw=Mat::zeros(Size(1024,1024), CV_8UC3);
	draw = Scalar(255, 255, 255);
	Rect rect;
	rect.x = 300, rect.y = 300, rect.width = 300, rect.height=300;
	rectangle(draw, rect, Scalar(0, 0, 255), 5/* -1 为填充*/, LINE_8);
	circle(draw, Point(300, 300), 50, Scalar(255, 0, 0), 5, LINE_8);
	//LINE_8后面还可以加一个数字int，表示绘图时留下的小数点位数
	imshow("Draw", draw);
	imshow("hz2016", img);
	//addWeighted(img,0.7,draw,0.3,0,ret);想让与透明色效果
	waitKey(0);
	return 0;
}
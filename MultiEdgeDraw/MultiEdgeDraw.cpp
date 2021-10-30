#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main() {
	Mat canvas = Mat::zeros(Size(1024, 1024), CV_8UC3);
	int w = canvas.cols, h = canvas.rows;
	canvas = Scalar(255, 255, 255);
	Point p1(100, 100), p2(250, 100), p3(330, 200), p4(450, 600), p5(150, 500);
	std::vector<Point>pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	/*
	fillPoly(canvas, pts, Scalar(255, 255, 0), LINE_8);
	//先填充后绘制，可以显示出绘制边界
	polylines(canvas, pts, true, Scalar(0, 0, 255), 2, LINE_AA);//此处-1不能进行填充，LINE_AA去锯齿
	*/
	std::vector<std::vector<Point>>contours;
	contours.push_back(pts);//可以一次绘制多个多边形
	drawContours(canvas, contours, -1, Scalar(255, 0, 0), 2,LINE_8);
	//-1为全部绘制，否则指定绘制某一个，此处的2为线宽
	imshow("Canvas", canvas);
	waitKey(0);
	return 0;
}
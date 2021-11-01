#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
using namespace cv;
Point st(-1, -1),ed(-1,-1);
bool onDown = false;
static void onDraw(int event, int x, int y, int flags, void *userdata) {
	Mat img = *((Mat*)userdata);
	/*
	x = std::max(std::min(x, img.cols), 0);
	y = std::max(std::min(y, img.rows), 0);
	其实这里的x已经是不会超出窗口的大小了，但是在下面计算dx,dy时不能+1,很可能在draw时爆炸
	*/
	if (event == EVENT_LBUTTONDOWN) {
		st.x = x, st.y = y;
		std::cout << "start point:" << st << std::endl;
		onDown = true;
	}
	else if (event == EVENT_LBUTTONUP) {
		ed.x = x, ed.y = y;
		std::cout << "end point:" << ed << std::endl;
		int dx = abs(ed.x - st.x), dy = abs(ed.y - st.y);
		Rect box(std::min(st.x,ed.x), std::min(st.y,ed.y), dx, dy);
		rectangle(img, box, Scalar(0, 0, 255), 2, LINE_8);
		imshow("Draw", img);
		imshow("Box", img(box));//提取区域图像
		onDown = false;
	}
	if (event == EVENT_MOUSEMOVE&&onDown) {
		Mat src;
		img.copyTo(src);
		ed.x = x, ed.y = y;
		std::cout << "move point:" << ed << std::endl;
		int dx = abs(ed.x - st.x), dy = abs(ed.y - st.y);
		Rect box(std::min(st.x, ed.x), std::min(st.y, ed.y), dx, dy);
		rectangle(src, box, Scalar(0, 0, 255), 2, LINE_8);
		imshow("Draw", src);
	}
}
int main() {
	Mat img = imread("hz2016.jpg");
	namedWindow("Draw");
	setMouseCallback("Draw", onDraw, (void*)(&img));
	imshow("Draw", img);
	waitKey(0);
	return 0;
}
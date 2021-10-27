#include <opencv2/opencv.hpp>
#include <ctime>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	Mat canvas = Mat::zeros(Size(1024, 1024), CV_8UC3);
	int w = canvas.cols, h = canvas.rows;
	RNG rng(time(0));//随机数种子默认rng(time(0))
	while (1) {
		int c = waitKey(10);
		if (c == 27)break;
		int x1=rng.uniform(0,w), x2= rng.uniform(0, w), y1= rng.uniform(0, h), y2= rng.uniform(0, h);
		int b = rng.uniform(0, 255), g = rng.uniform(0, 255), r = rng.uniform(0, 255);
		//canvas = Scalar(0, 0, 0);
		line(canvas,Point(x1,y1),Point(x2,y2),Scalar(b,g,r), 1, LINE_8);
		imshow("Rand", canvas);
	}
	waitKey(0);
	return 0;
}
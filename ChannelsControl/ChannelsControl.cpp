#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	imshow("hz2016", img);
	std::vector<Mat>mv;
	split(img, mv);
	imshow("Blue", mv[0]);
	imshow("Green", mv[1]);
	imshow("Red", mv[2]);
	Mat src;
	mv[1] = mv[2] = 0;
	merge(mv, src);
	imshow("True Blue", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
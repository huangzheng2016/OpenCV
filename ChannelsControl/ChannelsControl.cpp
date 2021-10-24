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
	Mat src1,src2;
	mv[1] = mv[2] = 0;
	merge(mv, src1);
	imshow("True Blue", src1);
	src2 = src1;
	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&img,1, &src2, 1, from_to, 3);
	imshow("Mix", src2);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
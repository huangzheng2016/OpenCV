#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	imshow("hz2016", img);
	int index = 0;
	while(1){
		int c = waitKey(2000);
		Mat src;
		applyColorMap(img, src, index);
		imshow("Show", src);
		index = (index + 1) % 19;
	}
	destroyAllWindows();
	return 0;
}
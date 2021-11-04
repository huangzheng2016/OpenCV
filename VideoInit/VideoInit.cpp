#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	VideoCapture capture(0);//0也可以换成一段视频
	Mat frame;
	while (1) {
		capture.read(frame);
		if (frame.empty())break;
		imshow("Frame", frame);
		int c = waitKey(1);
		if (c == 27)break;
	}
	waitKey(0);
	//capture.release();其实会主动放掉，但是多个摄像头要手动放
	return 0;
}
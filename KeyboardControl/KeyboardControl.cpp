#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	imshow("hz2016", img);
	while (1){
		int c=waitKey(0);
		if (c == 27)break;
		else if (c == 49)std::cout << "You enter key1" << std::endl;
		else if (c == 50)std::cout << "You enter key2" << std::endl;
		else if (c == 51)std::cout << "You enter key3" << std::endl;
	}
	destroyAllWindows();
	return 0;
}
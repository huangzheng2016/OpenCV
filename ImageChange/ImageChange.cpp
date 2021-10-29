#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	int h = img.rows,w=img.cols,dism=img.channels();
	//基于数组下标
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (dism == 1) {//灰度图像
				int pv = img.at<uchar>(i, j);
				img.at<uchar>(i, j) = 255 - pv;
			}
			else if (dism == 3) {//彩色图像
				Vec3b bgr = img.at<Vec3b>(i, j);//Vec3b 整数，Vec3f 实数
				img.at<Vec3b>(i, j)[0] = 255 - bgr[0];
				img.at<Vec3b>(i, j)[1] = 255 - bgr[1];
				img.at<Vec3b>(i, j)[2] = 255 - bgr[2];
			}
		}
	}
	*/
	//基于指针
	for (int i = 0; i < h; i++) {
		uchar* current_row = img.ptr<uchar>(i);
		for (int j = 0; j < w; j++) {
			if (dism == 1) {//灰度图像
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			else if (dism == 3) {//彩色图像
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
			//三个通道，只要指针偏移即可
		}
	}
	imshow("hz2016", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
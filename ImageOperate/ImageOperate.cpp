#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	Mat ret1 = img + Scalar(2, 2,2);
	Mat ret2,ret3,m;
	m = Mat::zeros(img.size(), img.type());
	ret2 = Mat::zeros(img.size(), img.type());
	m = Scalar(2 , 2, 2);
	multiply(img , m, ret2);//乘法
	imshow("hz2016-ret1", ret1);
	imshow("hz2016-ret2", ret2);
	//subtract()减法
	//divide()除法
	/*
	int h = img.rows, w = img.cols, dism = img.channels();
	for (int i = 0; i < h; i++) {
		uchar* current_row = img.ptr<uchar>(i);
		for (int j = 0; j < w; j++) {
			Vec3b p1 = img.at<Vec3b>(i, j);
			Vec3b p2 = m.at<Vec3b>(i, j);
			ret3.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
			ret3.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			ret3.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}//模拟加法
	imshow("hz2016-ret3", ret3);
	*/
	waitKey(0);
	destroyAllWindows();
	return 0;
}
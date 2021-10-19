#include <opencv2/opencv.hpp>
#include <cstdio>
//#include <iostream>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	/*
		Mat 头部-数据部分
		头部（数据类型，通道）-> 源数据
		Mat的赋值仅是指针，只有copy or clone才是复制一份新的
	*/
	Mat m1 = img.clone();
	Mat m2;
	img.copyTo(m2);
	Mat m3 = img;//此处指向的数据块是一样的，为指针
	Mat m4 = Mat::zeros(img.size(), img.type());
	Mat m5 = Mat::zeros(Size(512, 512), CV_8UC3);//CV_8UC3 8位的的Unsignchar 3通道
	Mat m6 = Mat::ones(Size(512, 512), CV_8UC3);//ones表示创造的mat里面全是1（仅在单通道！多通道仅第一个通道）
	//4,5,6为创建空白
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);//卷积矩阵
	imshow("m1", m1);
	imshow("m2", m2);
	imshow("m3", m3);
	imshow("m4", m4);
	imshow("m5", m5);
	printf("[m5: wight:%d high:%d channels:%d]\n", m5.cols, m5.rows, m5.channels());
	//m6=127;//将第一通道全部设置成127
	//m6=Scalar(127,127,127) 赋值多通道
	//std::cout<<m6<<std::endl;
	imshow("m6", m6);
	imshow("kernel", kernel);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
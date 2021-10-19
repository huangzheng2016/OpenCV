#include <opencv2/opencv.hpp>
//#include<cstdio>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg", IMREAD_GRAYSCALE);//Mat二位矩阵，引号内选一张自己计算机内的图片的路径
	/*
		默认加载三通道RBG图
		IMREAD_GRAYSCALE 灰度
		IMREAD_UNCHANGE 有透明通道，所以不会变（所有通道都是）
		IMREAD_ANYCOLOR 加载任意颜色
		IMREAD_ANYDEPTH 加载任意深度
	*/
	//if(img.empty())printf("Could not load image");
	namedWindow("hz2016", WINDOW_FREERATIO);//FREERATIO表示可以调整
	imshow("hz2016", img);//一个个变量为title，打开一个窗口，显示图片，默认窗体为AUTOSIZE
	waitKey(0);//在键盘敲入字符前程序处于等待状态，若不为0则为停顿x毫秒
	destroyAllWindows();//关闭所有窗口
	return 0;
}
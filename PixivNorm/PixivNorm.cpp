#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat img = imread("hz2016.jpg"),src, ret;
	img.convertTo(src,CV_32F);//float类型数据，alpha=1.0，beta=0.0[不改变通道]
	//CV_8UC3->CV32FC3
	/*
		Q:为什么要归一化？
		A:数据转化了之后只是变成了浮点，其数据并没有变化，要将其化为浮点数的图像才行
		L1归化：Ai/Sigma(A)
		L2归化：Ai/Sqrt(Sigma(A^2))+Min(C)([Alpha])
		INF归化：Ai/Max(A)
		MINMAX归化：根据在区间[Min,Max]中分别按比例对应[0,1]（[alpha,beta]）
	*/
	normalize(src, ret,0.0,1.0, NORM_MINMAX);//alpha,beta分别是MinMax比例中的高低值
	imshow("Norm", ret);
	waitKey(0);
	return 0;
}
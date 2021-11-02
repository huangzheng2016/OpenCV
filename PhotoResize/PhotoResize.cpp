#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat img = imread("hz2016.jpg"), src;
	/*
		Resize本质是对图像像素的重新取样（插值算法），常见的插值算法有
		双立方插值算法
		双线性内插值
		Lanczos采样放缩

		INTER_NEAREST - 最邻近插值 容易出锯齿
		INTER_LINEAR - 双线性插值，如果最后一个参数你不指定，默认使用这种方法
		INTER_AREA -区域插值(与最近邻插值类似) 缩小时有效避免波纹出现
		INTER_CUBIC - 4x4像素邻域内的双立方插值，三次立方采样 不容易出锯齿
		INTER_LANCZOS4 - 8x8像素邻域内的Lanczos插值 

		如果要缩小图像，通常推荐使用INTER_AREA插值效果最好，
		而要放大图像，通常使用INTER_CUBIC(速度较慢，但效果最好)，
		或者使用INTER_LINEAR(速度较快，效果还可以)。
	*/
	resize(img,src,Size(1024,1024),INTER_LINEAR);//fx,fy水平数值方向放缩多少，Size,fx,fy至少一个不为空
	imshow("Resize", src);
	waitKey(0);
	return 0;
}
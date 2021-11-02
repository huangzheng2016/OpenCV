#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg"), flipsrc,rotsrc;
	flip(img, flipsrc,-1);//1（左右翻转）,0（上下翻转）,-1（180°旋转）
	imshow("Flip", flipsrc);
	int w = img.cols, h = img.rows;
	Mat rot_mat = getRotationMatrix2D(Point(w / 2, h / 2), 45, 1.0);//中心点，角度，放大缩小
	double cos = rot_mat.at<double>(0, 0);
	double sin = rot_mat.at<double>(0, 1);
	int nw = cos * w + sin * h, nh = sin * w + cos * h;
	rot_mat.at<double>(0, 2)= (nw / 2 - w / 2);
	rot_mat.at<double>(1, 2)= (nh / 2 - h / 2);
	/*
		这里不能等于nw/2，因为只是相对坐标变了，里面存储的并不是其坐标的绝对量
		因为图像变化，所以在设计翻转矩阵时要重新处理他的翻转中心
		Mat[0]={角坐标,角坐标,中心点x}
		Mat[1]={角坐标,角坐标,中心点y}
	*/
	warpAffine(img, rotsrc, rot_mat, Size(nh,nw), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 0, 0));
	/*
		borderMode: 像素外推方法
		BORDER_CONSTANT -  补上定值，如果使用则补上的定值设置为borderValue的值（默认为0）
		BORDER_TRANSPARENT - 不做任何修改
		BORDER_REPLICATE - 将原始数据的行方向/列方向的边缘像素值作为外推边界(强行拉伸边界)
	*/
	imshow("Rotate", rotsrc);
	waitKey(0);
	return 0;
}
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
int main() {
	Mat img = imread("hz2016.jpg");
	imshow("hz2016", img);
	double maxx, minn;
	Point maxLoc, minLoc;
	std::vector<Mat>mv;
	split(img, mv);
	for (int i = 0; i < mv.size(); i++) {
		minMaxLoc(mv[i], &minn, &maxx, &minLoc, &maxLoc, Mat());//只能单通道
		//min,max,mean(均值),standard deviation(标准方差)
		std::cout<<"MV:" <<i<<" min vaule:" << minn << "  max vaule:" << maxx << std::endl;
	}
	Mat mean, standard;
	meanStdDev(img, mean, standard);
	std::cout << "mean:" << mean << std::endl;
	std::cout << "stddev" << standard << std::endl;
	std::cout << "mean0:" << mean.at<double>(0, 0) << std::endl;
	std::cout << "mean1:" << mean.at<double>(1, 0) << std::endl;
	std::cout << "mean2:" << mean.at<double>(2, 0) << std::endl;
	//stddev方差很小的时候，意思是对比度相近
	waitKey(0);
	destroyAllWindows();
	return 0;
}
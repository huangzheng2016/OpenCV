#include <opencv2/opencv.hpp>
using namespace cv;
static void on_lightness(int lightness, void* userdata) {
	Mat img = *((Mat*)userdata);
	Mat m = Mat::zeros(img.size(), img.type());
	Mat src = Mat::zeros(img.size(), img.type());
	addWeighted(img, 1.0, m, 0, lightness, src);
	imshow("Image Change", src);
}
static void on_contrast(int contrast, void* userdata) {
	Mat img = *((Mat*)userdata);
	Mat m = Mat::zeros(img.size(), img.type());
	Mat src = Mat::zeros(img.size(), img.type());
	double contrast_v = contrast / 100.0;
	addWeighted(img, contrast_v, m, 0.0, 0, src);
	imshow("Image Change", src);
}
int main() {
	Mat img = imread("hz2016.jpg");
	namedWindow("Image Change", WINDOW_AUTOSIZE);
	int max_lightness = 200, lightness = 50;
	int max_contrast = 200, contrast = 100;
	createTrackbar("Light:", "Image Change", &lightness, max_lightness, on_lightness, (void*)(&img));
	createTrackbar("Contrast:", "Image Change", &contrast, max_contrast, on_contrast, (void*)(&img));
	waitKey(0);
	destroyAllWindows();
	return 0;
}
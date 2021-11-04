#include <opencv2/opencv.hpp>
#include <iostream>
#include <time.h>
#define USBCamera
#define Resolution720P
using namespace cv;
int main() {
	#if defined LOCALCamera
		VideoCapture capture(0);//0也可以换成一段视频,0为主机自带摄像头，1为usb摄像头
	#else defined USBCamera
		VideoCapture capture(0);
		#if defined Resolution720P
			capture.set(CAP_PROP_FRAME_WIDTH, 1280);
			capture.set(CAP_PROP_FRAME_HEIGHT, 720);
			capture.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));//MJPG压缩格式，有效提高帧率
			//你要set一个支持的分辨率
		#endif
	#endif
	int frame_width = capture.get(CAP_PROP_FRAME_WIDTH), frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);//视频宽高
	std::cout << "width:" << frame_width << " height:" << frame_height<<std::endl;
	/*
		int count = capture.get(CAP_PROP_FRAME_COUNT);//总帧
		std::cout << "count:" << count << std::endl;//摄像头没有总帧数
		int fps = capture.get(CAP_PROP_FPS);//FPS
		std::cout << "fps:" << fps << std::endl;
		//摄像头的帧率读取实际上并不是十分稳定的，根据带宽、线程等特点会有帧率的丢失或者冗余，读取帧率多数会不成功
	*/
	Mat frame;
	VideoWriter writer("test.avi", capture.get(CAP_PROP_FOURCC), 30, Size(frame_width, frame_height));//保存视频，不要超过2G
	//mp4是压缩文件，不能直接存储，avi才是MJPG的压缩格式，先保存为一个确定的fps，后期再进行转码
	time_t start, end;
	int fps_frame=0;
	double fps,second;
	time(&start);
	while (1) {
		capture.read(frame);fps_frame++;
		if (frame.empty())break;
		imshow("Video", frame);
		writer.write(frame);
		int c = waitKey(1);
		if (c == 27)break;

	}
	time(&end);
	second = difftime(end, start);
	fps = double(fps_frame) / second;
	std::cout << "fps:" << fps << std::endl;//通过时间差获得网络摄像头的FPS
	//capture.release();其实会主动放掉，但是多个摄像头要手动放,writer也要
	return 0;
}
#ifndef UMC_ADB_H
#define UMC_ADB_H

#include <string>

#include "umc_common.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"       // 核心组件
#include "opencv2/highgui/highgui.hpp"  // GUI
#include "opencv2/imgproc/imgproc.hpp"  // 图像处理

using namespace std;

	
class UMC_ADB
{
public:
	UMC_ADB(const string& serial = "");
	~UMC_ADB();

	cv::Mat CapturePicture();
	float AnalyzeGPU();
	void Tap(float x, float y);

private:
	void Shell(const char* command, char* result) const;
	void Pull(const char* command, char* result) const;

private:
	string m_serial;
};

#endif
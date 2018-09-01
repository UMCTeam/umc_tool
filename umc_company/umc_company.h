#ifndef UMC_COMPANY_H
#define UMC_COMPANY_H
#	define UMC_COMPANY_API __declspec(dllexport)
#else
#	define UMC_COMPANY_API __declspec(dllimport)
#endif // !UMC_COMPANY_H

#include <iostream>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"       // 核心组件
#include "opencv2/highgui/highgui.hpp"  // GUI
#include "opencv2/imgproc/imgproc.hpp"  // 图像处理

UMC_COMPANY_API void hello();

UMC_COMPANY_API void  matchAndroidWidget(char* tpl, char* dst);
UMC_COMPANY_API float analyzeAndroidGPU(const char path[]);


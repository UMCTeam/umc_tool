#ifndef UMC_COMPANY_H
#	define UMC_COMPANY_API __declspec(dllexport)

#else
#	define UMC_COMPANY_API __declspec(dllimport)
#endif // !UMC_COMPANY_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"       // �������
#include "opencv2/highgui/highgui.hpp"  // GUI
#include "opencv2/imgproc/imgproc.hpp"  // ͼ����

UMC_COMPANY_API void hello();

UMC_COMPANY_API void cv_match(char* tpl, char* dst);
UMC_COMPANY_API float overdrawAnalyze(const char path[]);


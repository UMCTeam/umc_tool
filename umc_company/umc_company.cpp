#include "umc_company.h"

using namespace std;
using namespace cv;

UMC_COMPANY_API void hello() {
	cout << "hello" << endl;
}

UMC_COMPANY_API void cv_match(char* tpl, char* dst) {
	Mat m_tpl = imread(tpl);
	Mat m_dst = imread(dst);
	Mat im_result;
	m_dst.copyTo(im_result);

	Mat result;
	int result_cols = m_dst.cols - m_tpl.cols + 1;
	int result_rows = m_dst.rows - m_tpl.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);

	//模板匹配
	matchTemplate(m_dst, m_tpl, result, 4);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	//获取匹配度最高位置
	Point matchLoc;
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
	matchLoc = maxLoc;

	//显示匹配位置
	rectangle(im_result, matchLoc, Point(matchLoc.x + m_tpl.cols, matchLoc.y + m_tpl.rows), Scalar(0, 0, 255), 4, 4);
	imwrite("c:\\test.png", im_result);
	waitKey(0);
}

UMC_COMPANY_API float overdrawAnalyze(const char path[]) {
	CvMat cvmat = imread(path);
	IplImage* hsv = cvCreateImage(cvGetSize(&cvmat), 8, 3);
	//IplImage* dst_hsv = cvCreateImage(cvGetSize(&cvmat), 8, 3);
	cvGetImage(&cvmat, hsv);

	int width = hsv->width;
	int height = hsv->height;
	long double  red_number = 0;

	//阈值 0 - 255；
	int limit = 100;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			CvScalar color = cvGet2D(hsv, i, j);
			double b = color.val[0];
			double g = color.val[1];
			double r = color.val[2];

			double dst_r = (1 - (abs(g - b) / 255.0)) * (1 - (g + b) / (500.0)) * r;

			if (dst_r > limit) {
				++red_number;
			}

			//dst_r = dst_r > limit ? 255 : 0;
			//CvScalar dst_color(0, 0, dst_r);
		//	cvSet2D(dst_hsv, i, j, dst_color);
		}
	}

	//CvMat* dst = cvCreateMat(dst_hsv->height, dst_hsv->width, CV_8UC3);
	//cvConvert(dst_hsv, dst);

	//imwrite("c:\\test.png", Mat(dst->rows, dst->cols, dst->type, dst->data.fl));

	return red_number / (float)(hsv->width * hsv->height);
}
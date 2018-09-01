#include "umc_adb.h"

UMC_ADB::UMC_ADB(const string& serial)
	:m_serial(serial)
{

}

UMC_ADB::~UMC_ADB()
{
}

cv::Mat UMC_ADB::CapturePicture()
{
	char result[2048] = {0};
	char command[] = "screencap -p /data/local/tmp/screen.png && adb pull /data/local/tmp/screen.png";
	Shell(command, result);

	return cv::imread("screen.png");
}

float UMC_ADB::AnalyzeGPU()
{
	cv::Mat mat = CapturePicture();

	if (!mat.empty()) {
		IplImage hsv = IplImage(mat);
		double  red_number = 0;
		int width = hsv.width;
		int height = hsv.height;

		//ãÐÖµ 0 - 255£»
		int limit = 100;

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				CvScalar color = cvGet2D(&hsv, i, j);
				double b = color.val[0];
				double g = color.val[1];
				double r = color.val[2];

				double dst_r = (1 - (abs(g - b) / 255.0)) * (1 - (g + b) / (500.0)) * r;

				if (dst_r > limit) {
					++red_number;
				}
			}
		}

		return red_number / (float)(width * height);
	}

	return 0;
}


void UMC_ADB::Tap(float x, float y)
{
	char result[2048];
	string command = string("input tab ") + to_string(x) + " " + to_string(y);

	Shell(command.c_str(), result);
}

void UMC_ADB::Shell(const char* command, char* result) const
{
	const char* adb_command = NULL;
	string tmp;


	if (m_serial.length() > 0) {
		tmp = string("adb ") + string("-s ") + string("shell ") + string(m_serial) + string(command);
	}
	else {
		tmp = string("adb ") + string("shell ") + string(command);
	}

	executeCMD(tmp.c_str(), result);
}

void UMC_ADB::Pull(const char* command, char* result) const
{
	const char* adb_command = NULL;
	string tmp;

	if (m_serial.length() > 0) {
		tmp = string("adb ") + string("-s") + string("pull") + string(m_serial) + string(command);
	}
	else {
		tmp = string("adb ") + string("pull") + string(command);
	}

	executeCMD(tmp.c_str(), result);
}

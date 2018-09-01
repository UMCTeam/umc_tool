 // umc_tool.cpp: 定义应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS

#include "umc_tool.h"
#include "umc_common.h"
#include "umc_adb.h"

#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
	UMC_ADB* adb = new UMC_ADB();

	cout << string("请保证ADB 与手机连接通畅！") << endl;

	while (true)
	{
		stringstream out;
		float result = adb->AnalyzeGPU();
		out << "页面过度绘制占比:" << ">>" << result * 100 << "%";
		cout << out.str() << endl;

		Sleep(0);
	}

	delete adb;
}

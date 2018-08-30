 // umc_tool.cpp: 定义应用程序的入口点。
//

#include "umc_tool.h"
#include "umc_common.h"
#include "umc_company.h"
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{

	cout << string("请保证ADB 与手机连接通畅！") << endl;
	string tip_err = string("当前页面存在性能问题!");
	while (true)
	{
		char result[1024] = { 0 };
		
		//截取屏幕
		executeCMD("adb shell screencap -p /data/local/tmp/screen.png && adb pull /data/local/tmp/screen.png", result);
		
		//计算过度绘制
		float percent = overdrawAnalyze("screen.png");

		cout << (percent > 0.4? tip_err : "") << string("过度绘制面积:") << percent * 100 << "%" << endl;
		Sleep(0);
	}
	
}

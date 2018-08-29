 // umc_tool.cpp: 定义应用程序的入口点。
//

#include "umc_tool.h"
#include "umc_company.h"

using namespace std;

int main()
{
	float percent =	overdrawAnalyze("D:\\a.png");
	cout << percent << endl;
	return 0;
}

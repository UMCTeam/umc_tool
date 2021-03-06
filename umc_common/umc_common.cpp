// umc_common.cpp : 定义 DLL 应用程序的导出函数。
//

#include "umc_common.h"

void executeCMD(const char* cmd, char* result) {
	char buf_ps[1024];
	char ps[1024] = { 0 };
	FILE* ptr = NULL;
	
	strcpy(buf_ps, cmd);
	
	if ((ptr = _popen(buf_ps, "r")) != NULL) {
		while (fgets(buf_ps, sizeof(buf_ps), ptr) != NULL)
		{
			strcat(result, buf_ps);
		}

		_pclose(ptr);
		ptr = NULL;
	} else {
		cout << "cmd is error:" << cmd << endl;
	}
}

UMCLogger* UMCLogger::create(const string& filename)
{
	return new UMCLogger(filename);
}

void UMCLogger::console(const UMC_LOG& log)
{
	string log_text = "";
	string type = "";
	char* c_str = NULL;

	switch (log.type)
	{
	case ERROE:
		type = "error";
		break;
	case SUCCESS:
		type = "success";
		break;
	case WARN:
		type = "warn";
		break;
	default:
		type = "other";
	}

	log_text = log.title + "[" + type + "]" ">>" + log.text + "\n";
	m_file.write(log_text.c_str(), strlen(log_text.c_str()));
	m_file.flush();

	cout << log_text << endl;
}


UMCLogger::UMCLogger(const string& filename)
{
	m_file.open(filename, ios::out | ios::app);
	cout << string("UMC_LOGGER:") << endl;
}

UMCLogger::~UMCLogger()
{
	m_file.flush();
	m_file.close();
}


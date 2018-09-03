#ifndef UMC_COMMON_H
#define UMC_COMMON_H

#ifdef UMCCOMMON_EXPORTS
#	define UMC_COMMON_API _declspec(dllexport)
#else
#   define UMC_COMMON_API __declspec(dllimport)
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

UMC_COMMON_API void executeCMD(const char* cmd, char* result);


class UMC_COMMON_API UMCLogger
{
public:

	enum UMC_LOG_TYPE
	{
		WARN,
		SUCCESS,
		ERROE
	};

	struct UMC_LOG
	{
	public:
		UMC_LOG(const UMC_LOG_TYPE&& type, const string& title, const string& text) {
			this->type  = type;
			this->title = title;
			this->text  = text;
		}
		int type;
		string title;
		string text;
	};

	UMCLogger(const string& filename);
	~UMCLogger();

	static UMCLogger* create(const string& filename);
	void console(const UMC_LOG& log);

private:
	fstream m_file;
};


#endif
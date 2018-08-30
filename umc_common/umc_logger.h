#ifndef UMC_LOGGER_H
#	define UMC_LOGGER_API _declspec(dllexport)
#else
#   define UMC_LOGGER_API __declspec(dllimport)
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class UMC_LOGGER_API UMCLogger
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
		int type;
		string title;
		string text;
	};

	UMCLogger(const string& filename);
	~UMCLogger();

	UMCLogger* create(const string& filename);
	void console(const UMC_LOG& log);

private:
	ofstream m_file;
};
#include "umc_logger.h"

UMCLogger* UMCLogger::create(const string& filename)
{
	return new UMCLogger(filename);
}

void UMCLogger::console(const UMC_LOG& log)
{
	stringstream stext;
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

	stext << "¡¾" << type << "¡¿" << "¡¾" << type << "¡¿" << log.text;
	c_str = const_cast<char*> (stext.str().c_str());
	m_file.write(c_str, sizeof(c_str));

}


UMCLogger::UMCLogger(const string& filename)
{
	m_file.open(filename);
}

UMCLogger::~UMCLogger()
{
	m_file.close();
}

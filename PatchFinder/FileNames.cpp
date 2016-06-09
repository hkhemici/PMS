
#include "FileNames.h"

using namespace std;

FileNames::FileNames()
{
	list_ = {};
}

FileNames::FileNames(const std::string& switchName)
{
	for (unsigned int i = 0; i < 90; i++)
	{
		list_.push_back(switchName + ".sh_int_stat." + to_string(dates_.getYYYYMMDD()[i]) + ".txt");
	}
}

FileNames::~FileNames()
{
	//
}

std::vector<std::string> FileNames::getList()
{
	return list_;
}

Dates FileNames::getDates()
{
	return dates_;
}


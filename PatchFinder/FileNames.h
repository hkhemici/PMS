
#ifndef FILENAMES_H
#define FILENAMES_H

#include "Dates.h"
#include <vector>
#include <string>

class FileNames
{
public:
	FileNames();
	FileNames(const std::string& switchName);
	~FileNames();

	std::vector<std::string> getList();
	Dates getDates();

private:
	std::vector<std::string> list_;
	Dates dates_;
};

#endif // !FILENAMES_H

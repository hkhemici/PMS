
#ifndef FILENAMES_H
#define FILENAMES_H

#include "Dates.h"
#include <vector>

class FileNames
{
public:
	FileNames();
	FileNames(const std::string& switchName);
	~FileNames();

	Dates getDates();

private:
	std::vector<std::string> list_;
	Dates dates_;
};

#endif // !FILENAMES_H

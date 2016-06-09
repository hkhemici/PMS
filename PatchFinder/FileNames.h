
#ifndef FILENAMES_H
#define FILENAMES_H

#include <vector>

class FileNames
{
public:
	FileNames();
	FileNames(const std::string& switchName);
	~FileNames();

private:
	std::vector<std::string> list_;
};

#endif // !FILENAMES_H

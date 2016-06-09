
#ifndef READER_H
#define READER_H

#include <string>

class Reader
{
public:
	Reader();
	~Reader();

	bool checkPortInFile(const std::string& fileName, const int& port);

private:
};


#endif // !READER_H

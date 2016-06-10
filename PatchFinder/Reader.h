
#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <iostream> // to test.

class Reader
{
public:
	Reader();
	~Reader();

	void checkPortInFile(const std::string& fileName/*, const int& port*/); // USE \\ in string for \.

private:
};


#endif // !READER_H

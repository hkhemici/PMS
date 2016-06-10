
#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <iostream> // to test.
#include <sstream>
#include <exception>

class Reader
{
public:
	Reader();
	~Reader();

	bool verifyPortName(const std::string& portName, const int& switchNumber, const int& port);

	bool checkPortInFile(const std::string& fileName, // USE \\ in string for \.
						const int& switchNumber,
						const int& port); 

private:
};


#endif // !READER_H

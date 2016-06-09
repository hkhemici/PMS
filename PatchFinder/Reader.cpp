
#include "Reader.h"

using namespace std;

Reader::Reader()
{

}

Reader::~Reader()
{
	//delete[] YYYYMMDD_; // CAUSES BUG
}

bool Reader::checkPortInFile(const std::string& fileName, const int& port)
{
	return true; // TODO
}


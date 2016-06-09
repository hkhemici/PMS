
#include "Reader.h"

using namespace std;

Reader::Reader()
{
	//
}

Reader::~Reader()
{
	//
}

bool Reader::checkPortInFile(const std::string& fileName, const int& port)
{
	// Returns true if fileName has port active but not connected.
	string word;		// Used to read.
	ifstream file;
	file.open(fileName);
	while (file >> word)
	{
		if (word == "Type")
		{
			break;
		}
	}
	file >> word;
	//
	file.close();
	return true; // TODO: return
}


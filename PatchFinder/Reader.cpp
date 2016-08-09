
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

bool Reader::verifyPortName(const string& portName, const int& switchNumber, const int& port)
{
	// Check if it's the blank 2nd line in the log.
	if (portName.length() == 0)
	{
		return false;
	}

	// Convert 3rd character to int and check == switchNumber (always the 3rd character)
	if (portName[2] - '0' == switchNumber) 
	{
		// If port is < 10, check the last 2 characters of portName are "/port".
		if (port < 10)
		{
			if (portName.substr(portName.length() - 2) == "/" + to_string(port))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		// If port is >= 10, check the last 3 characters of portName are "/port".
		else
		{
			if (portName.substr(portName.length() - 3) == "/" + to_string(port))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

bool Reader::checkPortInFile(const std::string& fileName, const int& switchNumber, const int& port)
{
	// Returns true if fileName has port active but not connected.
	string line;		// Used to read.
	ifstream file;
	file.open(fileName);

	// Check failure in opening file (ex.: files are not generated on weekends).
	if (file.fail())
	{
		throw exception("File does not exist");
	}
	else
	{
		// Read each line.
		while (getline(file, line))
		{
			// Put first word of line in portName variable.
			istringstream lineStream(line);
			string portName;
			lineStream >> portName;

			// Check if portName is the port we are searching.
			if (verifyPortName(portName, switchNumber, port))
			{
				//cout << portName << "\t";
				// Look for "notconnect" in the line.
				size_t found = line.find("notconnect");
				if (found != string::npos)
				{
					//cout << "-- AVAILABLE --";
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	file.close();
}


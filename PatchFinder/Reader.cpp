
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

void Reader::checkPortInFile(const std::string& fileName/*, const int& port*/)
{
	// Returns true if fileName has port active but not connected.
	string line;		// Used to read.
	ifstream file;
	file.open(fileName);

	// Check failure in opening file (ex.: files are not generated on weekends).
	if (file.fail())
	{
		cout << "\nFILE DOES NOT EXIST.\n";
	}
	else
	{
		cout << "\n" << fileName << " opened successfully.\n";

		// Read each line.
		while (getline(file, line))
		{
			// Print line on console.
			cout << line << "\t";

			// Look for "notconnect" in the line.
			size_t found = line.find("notconnect");
			if (found != string::npos)
			{
				// If notconnect, print "available".
				cout << "-- AVAILABLE --";
			}
			cout << endl;
		}
	}


	file.close();
	// TODO: return
}


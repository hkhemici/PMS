#include <iostream>
#include <string>
#include <fstream>	// to read from file
#include "FileNames.h"
#include "Switch.h"

using namespace std;

void getSwitchName(string& name)
{
	cout << "\nEnter switch name: ";
	cin >> name;
}

void getSwitchPort(int& port)
{
	cout << "\nEnter port to verify: ";
	cin >> port;
}

bool readFile(/*const int& port, */const string&  fileName)
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
	cout << word;
	//
	file.close();
	return 0; // TODO: return
}

int main()
{
	// Initiate variables
	ifstream logFile;				// Read-only.
	bool portUsable = false;		//

	// Get switch name.
	string name;
	getSwitchName(name);

	// Get switch port.
	int port;
	getSwitchPort(port);

	// Create switch object.
	Switch PmsSwitch(name, port);
	
	// test
	cout << "\n\nFiles to read:\n";
	for (int i = 0; i < 90; i++)
	{
		cout << PmsSwitch.getLogs().getList()[i] << endl;
	}

}
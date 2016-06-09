#include <iostream>
#include <string>
#include "FileNames.h"
#include "Switch.h"
#include "Reader.h"

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
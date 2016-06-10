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

void getSwitchNumber(int& number)
{
	cout << "\nEnter switch number: ";
	cin >> number;
}

void getSwitchPort(int& port)
{
	cout << "\nEnter port to verify: ";
	cin >> port;
}

int main()
{
	// Initiate variables
	bool portUsable = false;
	cout << "PATCH KING 3000\n\n";

	// Get switch name.
	string name;
	getSwitchName(name);

	// Get switch number.
	int number;
	getSwitchNumber(number);

	// Get switch port.
	int port;
	getSwitchPort(port);

	// Create switch object.
	Switch PmsSwitch(name, number, port);

	// _______________________________________________________
	// TEMPORARY, WILL BECOME \\MONITOR02...
	vector<string> localNames;
	for (int i = 0; i < 90; i++)
	{
		localNames.push_back("E:\\Downloads\\RM-SW-52-2016-06-09\\RM-SW-52\\" + PmsSwitch.getLogs().getList()[i]);
	}
	// _______________________________________________________


	// test Reader class with given switch log file.
	Reader reader;

	for (int i = 0; i < 90; i++)
	{
		if (reader.checkPortInFile(localNames[i], number, port))
		{
			cout << "Port " << port << " is AVAILABLE on " << PmsSwitch.getLogs().getDates().getYYYYMMDD()[i] << endl;
		}
		else
		{
			cout << "Port " << port << " is NOT AVAILABLE on " << PmsSwitch.getLogs().getDates().getYYYYMMDD()[i] << endl;
		}
	}
}
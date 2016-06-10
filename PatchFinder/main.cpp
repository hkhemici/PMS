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
	bool portUsable = false;
	cout << "test start.\n\n";

	// Get switch name.
	string name;
	getSwitchName(name);

	// Get switch port.
	int port;
	getSwitchPort(port);

	// Create switch object.
	Switch PmsSwitch(name, port);
	
	// test log file names generation.
	cout << "\n\nFiles to read:\n";
	for (int i = 0; i < 90; i++)
	{
		cout << PmsSwitch.getLogs().getList()[i] << endl;
	}

	// test Reader class with given switch log file.
	Reader reader;
	reader.checkPortInFile("E:\\Downloads\\RM-SW-52-2016-06-09\\RM-SW-52\\RM-SW-52.sh_int_stat.20130123.txt");

}
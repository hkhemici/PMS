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
	cout << "\nEnter switch/stack number: ";
	cin >> number;
}

void getSwitchPort(int& port)
{
	cout << "\nEnter port to verify: ";
	cin >> port;
	cout << endl;
}

bool askTryAgain()
{
	cout << "\nDo you want to try another port on the same switch? (y/n): ";
	char answer;
	cin >> answer;
	cout << "\n\n";
	return answer == 'y' ? true : false;
}

int main()
{

	// Initiate variables
	bool tryAgain = true;
	cout << "\n////////////////////////////////////////////////////" <<
		"\n//                                                //" <<
		"\n//                 PATCH KING 3000                //" <<
		"\n//                     v 1.0.1                    //" <<
		"\n//                                                //" <<
		"\n////////////////////////////////////////////////////" <<
		"\n\n* Documentation on https://github.com/hkhemici/PMS *\n";

	// Get switch name.
	string name;
	getSwitchName(name);

	while (tryAgain)
	{
		// Initiate portUsable variable for each loop.
		bool portUsable = true;

		// Get switch number.
		int number;
		getSwitchNumber(number);

		// Get switch port.
		int port;
		getSwitchPort(port);

		// Create switch object.
		Switch PmsSwitch(name, number, port);

		// Build localNames.
		vector<string> localNames;
		for (int i = 0; i < 90; i++)
		{
			//localNames.push_back("C:\\Users\\hkhemici\\Documents\\RM-SW-52\\" + PmsSwitch.getLogs().getList()[i]);
			localNames.push_back("\\\\MONITOR02-RM\\Open_Switch_Ports$\\" + PmsSwitch.getName() + "\\" + PmsSwitch.getLogs().getList()[i]);
		}

		// Read files.
		Reader reader;


		for (int i = 0; i < 90; i++)
		{
			try
			{
				if (reader.checkPortInFile(localNames[i], number, port))
				{
					cout << "Port " << port << " is available on " << PmsSwitch.getLogs().getDates().getYYYYMMDD()[i] << endl;
				}
				else
				{
					cout << "Port " << port << " is -- NOT AVAILABLE -- on " << PmsSwitch.getLogs().getDates().getYYYYMMDD()[i] << endl;
					portUsable = false;
				}
			}
			catch (const std::exception& e)
			{
				cout << e.what() << " on " << PmsSwitch.getLogs().getDates().getYYYYMMDD()[i] << endl;
			}

		}

		// Final message.
		if (portUsable)
		{
			cout << "\nThe port CAN be used to patch a user!\n" << endl;
		}
		else
		{
			cout << "\nThe port CANNOT be used to patch a user.\n" << endl;
		}

		tryAgain = askTryAgain();
	}
}
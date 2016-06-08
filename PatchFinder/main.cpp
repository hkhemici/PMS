#include <iostream>
#include <string>
#include <fstream>	// to read from file
#include <ctime>	

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

struct tm getToday()
{
	time_t rawTime;	
	struct tm today;
	time(&rawTime);
	localtime_s(&today, &rawTime);
	return today;

	/*cout << "Today is " << today.tm_mday << " / " 
						<< today.tm_mon + 1 << " / "
						<< today.tm_year + 1900 << "\n\n";*/
}

void getDates(int* dates)
{
	struct tm today = getToday();
	for (int i = 0; i < 90; i++)
	{
		today.tm_mday -= 1;		// - 1 day per loop.
		mktime(&today);			// Standardize.
		dates[i] = 10000 * (today.tm_year + 1900) + // year + 1900 for correctness.
			100 * (today.tm_mon + 1) + // month + 1 for correctness.
			today.tm_mday;
	}
}

int main()
{
	// Initiate variables
	string switchName = "";			// Name of switch.
	int switchPort;					// Port # to verify.
	string logFileName = "";		// logFile = "\\\\MONITOR02-RM\\Open_Switch_Ports$\\" + switchName;
	ifstream logFile;				// Read-only.
	bool portUsable = false;		//
	int* dates = new int[90];		// array of dates from yesterday to 3 months ago (90 days).

	// Get switch name and port to verify.
	getSwitchName(switchName);
	getSwitchPort(switchPort);
	
	// Fill dates array
	getDates(dates);
	// test
	for (int i = 0; i < 90; i++)
	{
		cout << switchName << ".sh_int_stat." << dates[i] << ".txt" << endl;
	}

	return 0;
}
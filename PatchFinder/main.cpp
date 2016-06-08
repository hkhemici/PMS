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

int main()
{
	// Initiate variables
	string switchName = "";			// Name of switch.
	int switchPort;					// Port # to verify.
	string logFileName = "";		// 
	ifstream logFile;				// Read-only.
	bool portUsable = false;		//
	int* dates = new int[90];		// array of dates from yesterday to 3 months ago (90 days).

	// Get switch name and port to verify.
	getSwitchName(switchName);
	getSwitchPort(switchPort);

	//// Build log file name (\\ for 1 \)
	//// NON-OPTIMAL: NO NEED TO GET FOLDER, GET 90 TEXT FILES
	//logFile = "\\\\MONITOR02-RM\\Open_Switch_Ports$\\" + switchName;
	
	// Fill dates array
	cout << "Today is " << getToday().tm_mday << " / "
						<< getToday().tm_mon + 1 << " / "
						<< getToday().tm_year + 1900 << "\n\n";


	return 0;
}
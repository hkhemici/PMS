#include <iostream>
#include <string>
#include <fstream>	// to read from file
#include <ctime>

using namespace std;

int main()
{
	// Initiate variables
	string switchName = "";
	int switchPort;
	string logFileName = "";
	ifstream logFile;	// read-only
	bool portUsable = false;
	int* dates = nullptr;	// array of dates from yesterday to 3 months ago.

	// Get switch name
	cout << "Enter switch name: ";
	cin >> switchName;

	// Get switch port
	cout << "\nEnter port to verify: ";
	cin >> switchPort;

	//// Build log file name (\\ for 1 \)
	//// NON-OPTIMAL: NO NEED TO GET FOLDER, GET 90 TEXT FILES
	//logFile = "\\\\MONITOR02-RM\\Open_Switch_Ports$\\" + switchName;
	
	// Fill dates array


	// 
	





}
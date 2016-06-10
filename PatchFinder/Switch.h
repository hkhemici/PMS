#ifndef SWITCH_H
#define SWITCH_H

#include <string>
#include <iostream>
#include "FileNames.h"

class Switch
{
public:
	// Constructor & Destructor.
	Switch();
	Switch(const std::string& name, const int& number, const int& port);
	~Switch();

	// Access methods.
	std::string getName();
	int getNumber();
	int getPort();
	FileNames getLogs();

	// Modifier methods.

private:
	std::string name_;
	int number_;
	int portWanted_;
	FileNames logs_;
};

#endif // !SWITCH_H

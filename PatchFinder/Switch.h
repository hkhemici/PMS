#ifndef SWITCH_H
#define SWITCH_H

#include <string>
#include "FileNames.h"

class Switch
{
public:
	Switch();
	~Switch();
private:
	std::string name_;
	int portWanted_;
	FileNames logs;
};

#endif // !SWITCH_H

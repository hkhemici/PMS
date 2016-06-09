
#include "Switch.h"

using namespace std;

Switch::Switch()
{
	//
}

Switch::Switch(const string& name, const int& port)
	: name_(name), portWanted_(port)
{
	// logs?
}

Switch::~Switch()
{
	// Rien à détruire dans ce cas-ci (aucune utilisation de "new").
}

string Switch::getName()
{
	return name_;
}

int Switch::getPort()
{
	return portWanted_;
}

FileNames Switch::getLogs()
{
	return logs_;
}
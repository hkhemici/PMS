
#include "Switch.h"

using namespace std;

Switch::Switch()
{
	//
}

Switch::Switch(const string& name, const int& number, const int& port)
	: name_(name), number_(number), portWanted_(port)
{
	logs_ = FileNames(name_);
}

Switch::~Switch()
{
	// Rien à détruire dans ce cas-ci (aucune utilisation de "new").
}

string Switch::getName()
{
	return name_;
}

int Switch::getNumber()
{
	return number_;
}

int Switch::getPort()
{
	return portWanted_;
}

FileNames Switch::getLogs()
{
	return logs_;
}
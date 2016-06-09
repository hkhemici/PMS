#ifndef DATES_H
#define DATES_H

#include <ctime>

class Dates
{
public:
	Dates();
	~Dates();
	int* getYYYYMMDD();

private:
	int* YYYYMMDD_;
};


#endif // !DATES_H

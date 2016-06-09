
#include "Dates.h"

using namespace std;

Dates::Dates()
{
	YYYYMMDD_ = new int[90];

	time_t rawTime;
	struct tm today;
	time(&rawTime);
	localtime_s(&today, &rawTime);
	
	for (int i = 0; i < 90; i++)
	{
		today.tm_mday -= 1;								// - 1 day per loop.
		mktime(&today);									// Standardize.
		YYYYMMDD_[i] = 10000 * (today.tm_year + 1900) +	// year + 1900 for correctness.
			100 * (today.tm_mon + 1) +					// month + 1 for correctness.
			today.tm_mday;
	}
}

Dates::~Dates()
{
	//delete[] YYYYMMDD_; // CAUSES BUG
}

int* Dates::getYYYYMMDD()
{
	return YYYYMMDD_;
}


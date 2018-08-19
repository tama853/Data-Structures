#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <chrono>
#include <string>
using std::string;
using highResClock = std::chrono::high_resolution_clock; //alias
using timePoint = highResClock::time_point;

class SimpleTimer
{
public:
	string message;
	timePoint start;
	timePoint end;
	std::chrono::duration<double> elapsed;

	SimpleTimer();
	SimpleTimer(const char*);
	~SimpleTimer();
};

#endif // SIMPLETIMER_H

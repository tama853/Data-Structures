#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <chrono>
#include <string>

using highResClock = std::chrono::high_resolution_clock; //alias
using timePoint = highResClock::time_point;
using std::string;

class SimpleTimer
{
public:
	string message;
	timePoint start;
	timePoint end;
	std::chrono::duration<double> elapsed;

	SimpleTimer();
	SimpleTimer(string);
	~SimpleTimer();
};

#endif // SIMPLETIMER_H

#include "SimpleTimer.h"
#include <iostream>
using std::endl;
using std::cout;
SimpleTimer::SimpleTimer()
{
	start = highResClock::now();
}

SimpleTimer::SimpleTimer(string msg)
{
	message = msg;
	start = highResClock::now(); //start after any addiional work
}

SimpleTimer::~SimpleTimer()
{
	end = highResClock::now(); //end before any additional work
	elapsed = end - start;
	cout << message << ": "<< elapsed.count() << " s" << endl;
}

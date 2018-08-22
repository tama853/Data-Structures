#include "SimpleTimer.h"
#include <iostream>
#include <iomanip>
using std::endl;
using std::cout;
using std::scientific;
using std::setprecision;

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
	cout << scientific;
	cout << message << ": " << setprecision(6) << elapsed.count() << " s" << endl;
}

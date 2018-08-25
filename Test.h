#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using std::vector;


template <typename T>
class Test
{
private:
	// defaults to 1000
	unsigned int size;
	SimpleTimer* timer;
	vector<T> numSorted;
	vector<T> numUnsorted;
	vector<T> nums; // temp that gets set within Set()

public:
	Test<T>(const unsigned int size = 1000) : size(size);
	void Test<T>::createVector<T>(vector<T>&, unsigned int);
};

template <typename T>
Test<T>::Test(const unsigned int size = 1000) : size(size)
{
	this->size = size;
	timer = nullptr;
	createVector(numUnsorted, this->size);
	numSorted = numUnsorted; // making sure they both will have the same values in list between testing
	sort(numSorted.begin(), numSorted.end()); // sorts list for use in sorted testing
}

template <typename T>
void Test::createVector(vector<T>& dataType, unsigned int _size)
{
	srand(time(0));

	for (unsigned int i = 0; i < _size; i++)
	{
		dataType.push_back(rand() % _size); //random numbers
		// add random strings
		// add random objects
	}
}

template <typename T>
void Test::print(const vector<T>& dataType)
{
	for (T tmp : dataType)
	{
		cout << tmp << " ";
	}
	cout << endl;
}

#endif // TEST_H

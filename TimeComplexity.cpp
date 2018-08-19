#include <iostream>
#include <string>
#include <vector>
#include "SimpleTimer.h"
#include <ctime>
using namespace std;


template <typename T>
void createVector(vector<T>& dataType, unsigned long long num)
{
//################### VECTOR SETUP ############################
	srand(time(0));

	for (unsigned long long i = 0; i < num; i++)
	{
		dataType.push_back(rand() % num); //random numbers
		// add random strings
		// add random objects
	}

	//for (T tmp : dataType)
	//	cout << tmp << " ";
	//cout << endl; 
}


void bubbleSort(vector<unsigned long long> nums)
{
	//test adding additionl brackets within function for scope of SimpleTimer
	SimpleTimer timer("Bubble Sort");
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (unsigned long long i = 0; i < nums.size(); i++)
		{
			if (nums[i] > nums[i + 1])
			{
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				swapped = true;
			}
		}
	}
//	for (unsigned long long tmp : nums)
//		cout << tmp << " ";
//	cout << endl;
}

void selectionSort(vector<unsigned long long> nums)
{
	SimpleTimer timer("Selection Sort");
}

void insertionSort(vector<unsigned long long> nums)
{
	SimpleTimer timer("Insertion Sort");
}

void quickSort(vector<unsigned long long> nums)
{
	SimpleTimer timer("Quick Sort");
}

void mergeSort(vector<unsigned long long> nums)
{
	SimpleTimer timer("Merge Sort");
}

void shellSort(vector<unsigned long long> nums)
{
	SimpleTimer timer("Shell Sort");
}

void binarySearch(vector<unsigned long long> nums)
{
	SimpleTimer timer("Binary Search");
}

void linearSearch(vector<unsigned long long> nums)
{
	SimpleTimer timer("Linear Search");
}

int main()
{
	// set size of vector
	unsigned long long size = 20000;
	vector<unsigned long long> nums;
	createVector(nums, size);

	// add average of sorting times
	// add fastest, slowest, fastest when sorted, and fastest when unsorted

	// Common Time Complexity                      Common Space Complexity
	// O( 1 ) - Constant
	// O( log(N) ) - Logarithmic
	// O( N ) - Linear
	// O( Nlog(N) ) - Log-Linear
	// O( N^2 ) - Quaudratic
	// O( c^N ) - Exponential

	// Time - O( N^2 ), Space - 
	bubbleSort(nums);

	// Time - O ( N^2 ), Space - 
// selectionSort(nums);
//
// Time - O(), Space - 
// insertionSort(nums);
//
// Time - O(), Space - 
// quickSort(nums);
//
// Time - O( Nlog(N) ), Space - 
// mergeSort(nums);
//
// Time - O( ), Space - 
// shellSort(nums);
//
// Time - O( log(N) ), Space - 
// binarySearch(nums);
//
// Time - O( N ), Space - 
// linearSearch(nums);
	return 0;	
}

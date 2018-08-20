#include <iostream>
#include <string>
#include <vector>
#include "SimpleTimer.h"
#include <ctime>
using namespace std;


template <typename T>
void createVector(vector<T>& dataType, unsigned long long num)
{
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

template <typename T>
void bubbleSort(vector<T> nums)
{
	SimpleTimer timer("Bubble Sort");
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (unsigned long long i = 0; i < nums.size(); i++)
		{
			if (nums[i] > nums[i + 1])
			{
				T tmp = nums[i];
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

template <typename T>
void selectionSort(vector<T> nums)
{
	SimpleTimer timer("Selection Sort");
	for (unsigned long long i = 0; i < nums.size(); i++)
	{
		// find index of smallest value
		int indexSmallest = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] < nums[indexSmallest])
			{
				indexSmallest = j;
			}
		}
		// swap
		T temp = nums[i];
		nums[i] = nums[indexSmallest];
		nums[indexSmallest] = temp;
	}
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
	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
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

	bubbleSort(nums);
	// Time - O( N^2 ), Space -
	// Each iteration slowly causes the list to be sorted by bubbling values in ascedning/descending order

	selectionSort(nums);
	// Time - O ( N^2 ), Space - 
	// Treats the input as 2 parts, sorted and unsorted. Selects the proper 
	// next value from unsorted part to move into the sorted part

	// Time - O(), Space - 
	// insertionSort(nums);

	// Time - O(), Space - 
	// quickSort(nums);

	// Time - O( Nlog(N) ), Space - 
	// mergeSort(nums);

	// Time - O( ), Space - 
	// shellSort(nums);

	// Time - O( log(N) ), Space - 
	// binarySearch(nums);

	// Time - O( N ), Space - 
	// linearSearch(nums);
	return 0;	
}

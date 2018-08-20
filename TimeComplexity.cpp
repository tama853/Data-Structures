#include <iostream>
#include <string>
#include <vector>
#include "SimpleTimer.h"
#include <ctime>
#include <algorithm>
using namespace std;


template <typename T>
void createVector(vector<T>& dataType, unsigned int num)
{
	srand(time(0));

	for (unsigned int i = 0; i < num; i++)
	{
		dataType.push_back(rand() % num); //random numbers
		// add random strings
		// add random objects
	}
}



template <typename T>
void print(const vector<T>& dataType)
{
	for (T tmp : dataType)
	{
		cout << tmp << " ";
	}
	cout << endl;
}

template <typename T>
void bubbleSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;

	if (sorted)
	{
		timer = new SimpleTimer("Bubble Sort Sorted");
	}
	else
	{
		timer = new SimpleTimer("Bubble Sort Unsorted");
	}

	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (unsigned int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				// swap
				T tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				swapped = true;
			}
		}
	}
	delete timer;
}

template <typename T>
void selectionSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Selection Sort Sorted");
	}
	else
	{
		timer = new SimpleTimer("Selection Sort Unsorted");
	}
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		// find index of smallest value of remaining elements
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
	delete timer;
}

template <typename T>
void insertionSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Insertion Sort Sorted");
	}
	else
	{
		timer = new SimpleTimer("Insertion Sort Unsorted");
	}
	for (unsigned int i = 1; i < nums.size(); i++)
	{
		for (unsigned int j = i; (j > 0) && (nums[j] < nums[j - 1]); j--)
		{
			// swap
			T temp = nums[j];
			nums[j] = nums[j - 1];
			nums[j - 1] = temp;
		}
	}
	delete timer;
}

template <typename T>
void quickSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Quick Sorted");
	}
	else
	{
		timer = new SimpleTimer("Quick Unsorted");
	}
}

template <typename T>
void mergeSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Merge Sorted");
	}
	else
	{
		timer = new SimpleTimer("Merge Unsorted");
	}
}

template <typename T>
void shellSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Shell Sorted");
	}
	else
	{
		timer = new SimpleTimer("Shell Unsorted");
	}
}

template <typename T>
void binarySearch(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Binary Search");
	}
	else
	{
		cout << "Not possible!" << endl;
	}
}

template <typename T>
void linearSearch(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Linear Search Sorted");
	}
	else
	{
		timer = new SimpleTimer("Linear Search Unsorted");
	}
}

template <typename T>
void heapSort(vector<T> nums, bool sorted = false)
{
	SimpleTimer* timer = nullptr;
	if (sorted)
	{
		timer = new SimpleTimer("Heap Sorted");
	}
	else
	{
		timer = new SimpleTimer("Heap Unsorted");
	}
}

int main()
{
	// set size of vector
	
	unsigned int size = 10000;
	vector<unsigned int> nums;
	vector<unsigned int> numSorted;
	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
	// unsorted list
	createVector(nums, size);
	createVector(numSorted, size);
	sort(numSorted.begin(), numSorted.end());

	// add average of sorting times
	// add fastest, slowest, fastest when sorted, and fastest when unsorted

	// Common Data Structures
	// Array, Stack, Queue, Singly-Linked List, Doubly-Linked List, Skip List, Hash Table, Binary Search Tree, Cartesian
	// Tree, B-Tree, Red-Black Tree, Splay Tree, AVL Tree, KD Tree

	// Common Time Complexity                      Common Space Complexity
	// O( 1 ) - Constant
	// O( log(N) ) - Logarithmic
	// O( N ) - Linear
	// O( Nlog(N) ) - Log-Linear
	// O( N^2 ) - Quaudratic
	// O( c^N ) - Exponential
	//
	//
	// Common Data Structure Operations

/*Data Structure	Time Complexity	Space Complexity
Average	Worst	Worst
Access	Search	Insertion	Deletion		Access		Search													Insertion	    Deletion	
Array	Θ(1)	Θ(n)	Θ(n)	Θ(n)	O(1)	O(n)	O(n)															O(n)		O(n)
Stack	Θ(n)	Θ(n)	Θ(1)	Θ(1)	O(n)	O(n)	O(1)	O(1)																O(n)
Queue	Θ(n)	Θ(n)	Θ(1)	Θ(1)	O(n)	O(n)	O(1)	O(1)																O(n)
Singly-Linked List	Θ(n)	Θ(n)	Θ(1)	Θ(1)	O(n)	O(n)	O(1)	O(1)													O(n)
Doubly-Linked List	Θ(n)	Θ(n)	Θ(1)	Θ(1)	O(n)	O(n)	O(1)	O(1)													O(n)
Skip List	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(n)	O(n)	O(n)	O(n)									 O(n log(n))
Hash Table	N/A	Θ(1)	Θ(1)	Θ(1)	N/A	O(n)	O(n)	O(n)	O(n)
Binary Search Tree	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(n)	O(n)	O(n)	O(n)									O(n)
Cartesian Tree	N/A	Θ(log(n))	Θ(log(n))	Θ(log(n))	N/A	O(n)	O(n)	O(n)	O(n)
B-Tree	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(log(n))	O(log(n))	O(log(n))	O(log(n))								O(n)
Red-Black Tree	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(log(n))	O(log(n))	O(log(n))	O(log(n))						O(n)
Splay Tree	N/A	Θ(log(n))	Θ(log(n))	Θ(log(n))	N/A	O(log(n))	O(log(n))	O(log(n))	O(n)
AVL Tree	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(log(n))	O(log(n))	O(log(n))	O(log(n))							O(n)
KD Tree	Θ(log(n))	Θ(log(n))	Θ(log(n))	Θ(log(n))	O(n)	O(n)	O(n)	O(n)	O(n)
*/

/*	Array Sorting Algorithms

Algorithm	Time Complexity	Space Complexity
Best	Average	Worst	Worst
Quicksort	Ω(n log(n))	Θ(n log(n))	O(n^2)	O(log(n))
Mergesort	Ω(n log(n))	Θ(n log(n))	O(n log(n))	O(n)
Timsort	Ω(n)	Θ(n log(n))	O(n log(n))	O(n)
Heapsort	Ω(n log(n))	Θ(n log(n))	O(n log(n))	O(1)
Bubble Sort	Ω(n)	Θ(n^2)	O(n^2)	O(1)
Insertion Sort	Ω(n)	Θ(n^2)	O(n^2)	O(1)
Selection Sort	Ω(n^2)	Θ(n^2)	O(n^2)	O(1)
Tree Sort	Ω(n log(n))	Θ(n log(n))	O(n^2)	O(n)
Shell Sort	Ω(n log(n))	Θ(n(log(n))^2)	O(n(log(n))^2)	O(1)
Bucket Sort	Ω(n+k)	Θ(n+k)	O(n^2)	O(n)
Radix Sort	Ω(nk)	Θ(nk)	O(nk)	O(n+k)
Counting Sort	Ω(n+k)	Θ(n+k)	O(n+k)	O(k)
Cubesort	Ω(n)	Θ(n log(n))	O(n log(n))	O(n)
*/


	bubbleSort(nums);
	// Time - O( N^2 ), Space -
	// Each iteration slowly causes the list to be sorted by 
	// bubbling values in ascedning/descending order.
	
	selectionSort(nums);
	// Time - O( N^2 ), Space - 
	// Treats the input as 2 parts, sorted and unsorted. Selects the proper 
	// next value from unsorted part to move into the sorted part.

	insertionSort(nums); 
	// Time - O( N^2 ) but can act like O( N ) on sorted or partitallt sorted list, Space - 
	// Likd selection sort, it treats the input as 2 parts. It then repeatedly 
	// inserts the next value into the correct sorted location.

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

	// sorted list
	bubbleSort(numSorted, true);
	selectionSort(numSorted, true);
	insertionSort(numSorted, true);
	return 0;
}

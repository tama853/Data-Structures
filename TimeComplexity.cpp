#include <iostream>
#include <string>
#include <vector>
#include "SimpleTimer.h"
#include <ctime>
#include <algorithm>
using namespace std;


template <typename T>
struct Test
{
	// defaults to 1000
	unsigned int size;
	SimpleTimer* timer;
	vector<T> numSorted;
	vector<T> numUnsorted;
	vector<T> nums; // temp that gets set within Set()

	Test(const unsigned int size = 1000) : size(size)
	{
		this->size = size;
		timer = nullptr;
		createVector(numUnsorted, this->size);
		numSorted = numUnsorted; // making sure they both will have the same values in list between testing
		sort(numSorted.begin(), numSorted.end()); // sorts list for use in sorted testing
	}

	void createVector(vector<T>& dataType, unsigned int _size)
	{
		srand(time(0));

		for (unsigned int i = 0; i < _size; i++)
		{
			dataType.push_back(rand() % _size); //random numbers
			// add random strings
			// add random objects
		}
	}

	void print(const vector<T>& dataType)
	{
		for (T tmp : dataType)
		{
			cout << tmp << " ";
		}
		cout << endl;
	}

	void Set(bool sorted = false)
	{
		if (sorted)
		{
			nums = numSorted;
			timer = new SimpleTimer("Sorted ");
		}
		else
		{
			nums = numUnsorted;
			timer = new SimpleTimer("Unsorted ");
		}
	}

	void bubbleSort(bool sorted = false)
	{
		Set(sorted);
		// using while loop on sorted lists bubble sort is O(N)
		//bool swapped = true;
		//while (swapped)
		for (unsigned int i = 0; i < nums.size() - 1; i++)
		{
			//swapped = false;
			for (unsigned int j = 0; j < nums.size() - 1 - i; j++)
			{
				if (nums[j] > nums[j + 1])
				{
					// swap
					T tmp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = tmp;
					//swapped = true;
					// can test with references
					// swap(&nums[j], &nums[j + 1]);
				}
			}
		}
		cout << "Bubble Sort" << endl;
		delete timer;
	}

	void selectionSort(bool sorted = false)
	{
		Set(sorted);

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
		cout << "Selction Sort" << endl;
		delete timer;
	}

	void insertionSort(bool sorted = false)
	{
		Set(sorted);

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
		cout << "Insertion Sort" << endl;
		delete timer;
	}

	unsigned int partition(unsigned int left, unsigned int right, unsigned int pivot)
	{
		while (left <= right)
		{
			while (nums[left] < pivot)
			{
				left++;
			}

			while (nums[right] > pivot)
			{
				right--;
			}

			if (left <= right)
			{
				T temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
				left++;

				if (right != 0)
				{
				right--; // todo fix later
				}
			}
		}
		return left;
	}

	void recursiveQuickSort(unsigned int left, unsigned int right)
	{
		if (left < right)
		{
			unsigned int pivot = nums[left + ((right - left) / 2)];  // try differnt pivots
			unsigned int partitionIndex = partition(left, right, pivot);
			recursiveQuickSort(left, partitionIndex - 1);
			recursiveQuickSort(partitionIndex, right);
		}
	}

	void quickSort(bool sorted = false)
	{
		Set(sorted);
		recursiveQuickSort(0, nums.size() - 1);
		cout << "Quick Sort" << endl;

		// avoids trying to unallocate a pointer that wasn't allocated
			delete timer;
	}
			
	void mergeSort(bool sorted = false)
	{
		Set(sorted);

		cout << "Merge Sort" << endl;
		delete timer;
	}

	void shellSort(bool sorted = false)
	{
		Set(sorted);

		cout << "Shell Sort" << endl;
		delete timer;
	}

	void binarySearch(bool sorted = false)
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

	void linearSearch(bool sorted = false)
	{
		Set(sorted);

		cout << "Linear Search" << endl;
		delete timer;
	}

	void heapSort(bool sorted = false)
	{
		Set(sorted);

		cout << "Heap Sort" << endl;
		delete timer;
	}
};


int main()
{
	const unsigned sizeOfList = 5;
	Test<unsigned int> tester(sizeOfList);

	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
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

	//tester.bubbleSort();
	// Time - O( N^2 ), Space -
	// Each iteration slowly causes the list to be sorted by 
	// bubbling values in ascedning/descending order.
	
	//tester.selectionSort();

	// Time - O( N^2 ), Space - 
	// Treats the input as 2 parts, sorted and unsorted. Selects the proper 
	// next value from unsorted part to move into the sorted part.

	tester.insertionSort();
	// Time - O( N^2 ) but can act like O( N ) on sorted or partially sorted list, Space - 
	// Likd selection sort, it treats the input as 2 parts. It then repeatedly 
	// inserts the next value into the correct sorted location.

	tester.quickSort();
	// Time - O(), Space - 
	// Chooses a pivot and then repeatedly partitions the list into high and low parts, 
	// each part unsorted, and then recursively sorts each part. 

	tester.mergeSort();
	// Time - O( Nlog(N) ), Space - 

	// shellSort(nums);
	// Time - O( ), Space - 

	// binarySearch(nums);
	// Time - O( log(N) ), Space - 

	// linearSearch(nums);
	// Time - O( N ), Space - 

	// sorted list
	tester.bubbleSort(true);
	tester.selectionSort(true);
	tester.insertionSort(true);
	tester.quickSort(true);
	tester.mergeSort(true);
	return 0;
}

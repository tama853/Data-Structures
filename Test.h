#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "SimpleTimer.h"

using std::vector;
using std::endl;
using std::cout;

template <typename T>
class Test
{
private:
	bool sorted = false;
	unsigned int size;
	SimpleTimer* timer;
	vector<T> numSorted;
	vector<T> numUnsorted;
	vector<T> nums;		// temp vector that gets set within Set() since I
				// didn't want to repeat sort on each sorted algorithm version

public:
	Test(unsigned int);
	void createVector(vector<T>&, unsigned int);
	void Set(bool sorted = false);
	void print(const vector<T>&);
	unsigned int GetNums();

	// algorithms
	unsigned int partition(unsigned int, unsigned int, unsigned int);
	void bubbleSort(bool sorted = false);
	void selectionSort(bool sorted = false);
	void insertionSort(bool sorted = false);
	void recursiveQuickSort(unsigned int, unsigned int);
	void quickSort(bool sorted = false);
	void mergeSort(bool sorted = false);
	void shellSort(bool sorted = false);
	void binarySearch(bool sorted = false);
	void linearSearch(bool sorted = false);
	void heapSort(bool sorted = false);
	void radixSort(bool sorted = false);
};

template <typename T>
Test<T>::Test(unsigned int size)
{
	if (size > 0)
	{
		this->size = size;
		timer = nullptr;
		createVector(numUnsorted, this->size);
		numSorted = numUnsorted; // making sure they both will have the same values in list between testing
		sort(numSorted.begin(), numSorted.end()); // sorts list for use in sorted testing
	}
	else
	{
		// todo fix error checking
		cout << "Invalid size, please rerun the programe with a size greater than 0." << endl;
	}
}

template <typename T>
void Test<T>::createVector(vector<T>& dataType, unsigned int _size)
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
void Test<T>::print(const vector<T>& dataType)
{
	for (T tmp : dataType)
	{
		cout << tmp << " ";
	}
	cout << endl;
}

template <typename T>
unsigned int Test<T>::GetNums()
{
	return nums.size();
}

template <typename T>
void Test<T>::Set(bool sorted)
{
	if (sorted)
	{
		nums = numSorted;
		timer = new SimpleTimer("    Sorted   ");
	}
	else
	{
		nums = numUnsorted;
		timer = new SimpleTimer("    Unsorted ");
	}
}

template <typename T>
void Test<T>::bubbleSort(bool sorted)
{
	Set(sorted);
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

template <typename T>
void Test<T>::selectionSort(bool sorted)
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

template <typename T>
void Test<T>::insertionSort(bool sorted)
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

template <typename T>
unsigned int Test<T>::partition(unsigned int left, unsigned int right, unsigned int pivot)
{
	bool done = false;

	while (!done)
	{
		while (nums[left] < pivot)
		{
			left++;
		}

		while (nums[right] > pivot)
		{
			right--;
		}

		// guards against going out of bounds
		if (left >= right)
		{
			done = true;
		}
		else
		{
			T temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;

			left++;
			right--;
		}
	}
	return right;
}

template <typename T>
void Test<T>::recursiveQuickSort(unsigned int left, unsigned int right)
{
	if (left >= right)
	{
		return;
	}

	unsigned int midPoint = left + ((right - left) / 2);  // try differnt pivots
	unsigned int pivot = nums[midPoint];
	unsigned int partitionIndex = partition(left, right, pivot);

	recursiveQuickSort(left, partitionIndex); // maybe partitionIndex - 1
	recursiveQuickSort(partitionIndex + 1, right); // maybe partitionIndex
}

template <typename T>
void Test<T>::quickSort(bool sorted)
{
	Set(sorted);
	recursiveQuickSort(0, nums.size() - 1);
	cout << "Quick Sort" << endl;

	// avoids trying to unallocate a pointer that wasn't allocated
		delete timer;
}
		
template <typename T>
void Test<T>::mergeSort(bool sorted)
{
	Set(sorted);

	cout << "Merge Sort" << endl;
	delete timer;
}

template <typename T>
void Test<T>::shellSort(bool sorted)

{
	Set(sorted);

	cout << "Shell Sort" << endl;
	delete timer;
}

template <typename T>
void Test<T>::binarySearch(bool sorted)
{
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
void Test<T>::linearSearch(bool sorted)
{
	Set(sorted);

	cout << "Linear Search" << endl;
	delete timer;
}

template <typename T>
void Test<T>::heapSort(bool sorted)
{
	Set(sorted);

	cout << "Heap Sort" << endl;
	delete timer;
}

template <typename T>
void Test<T>::radixSort(bool sorted)
{
	Set(sorted);

	cout << "Radix Sort" << endl;
	delete timer;
}

#endif // TEST_H

#include "SimpleTimer.h"
#include "Test.h"
#include "MyAlgorithms.h"

using std::cout;
using std::endl;

void MyAlgorithms::Set(bool sorted = false)
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

void MyAlgorithms::bubbleSort(bool sorted = false)
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

void MyAlgorithms::selectionSort(bool sorted = false)
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

void MyAlgorithms::insertionSort(bool sorted = false)
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

unsigned int MyAlgorithms::partition(unsigned int left, unsigned int right, unsigned int pivot)
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

void MyAlgorithms::recursiveQuickSort(unsigned int left, unsigned int right)
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

void MyAlgorithms::quickSort(bool sorted = false)

{
	Set(sorted);
	recursiveQuickSort(0, nums.size() - 1);
	cout << "Quick Sort" << endl;

	// avoids trying to unallocate a pointer that wasn't allocated
		delete timer;
}
		
void MyAlgorithms::mergeSort(bool sorted = false)
{
	Set(sorted);

	cout << "Merge Sort" << endl;
	delete timer;
}

void MyAlgorithms::shellSort(bool sorted = false)

{
	Set(sorted);

	cout << "Shell Sort" << endl;
	delete timer;
}

void MyAlgorithms::binarySearch(bool sorted = false)
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

void MyAlgorithms::linearSearch(bool sorted = false)
{
	Set(sorted);

	cout << "Linear Search" << endl;
	delete timer;
}

void MyAlgorithms::heapSort(bool sorted = false)
{
	Set(sorted);

	cout << "Heap Sort" << endl;
	delete timer;
}


int main(int argc, char* argv[])
{
	const unsigned int sizeOfList = stoi(argv[1]);
	//MyAlgorithms<unsigned int> tester(sizeOfList);
	Test<unsigned int> testObject(sizeOfList);
	MyAlgorithms run(testObject);
	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
	// add average of sorting times
	// add fastest, slowest, fastest when sorted, and fastest when unsorted

	
	
	run.selectionSort();
	tester.insertionSort();
	tester.quickSort();
	tester.mergeSort();
	// shellSort(nums);
	// binarySearch(nums);
	// linearSearch(nums);
	// sorted list
	tester.bubbleSort(true);
	tester.selectionSort(true);
	tester.insertionSort(true);
	tester.quickSort(true);
	tester.mergeSort(true);
	return 0;
}

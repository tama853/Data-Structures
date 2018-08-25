#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H

#include "Test.h"
using std::cout;
using std::endl;

class MyAlgorithms
{
private:
	Test testObject; // todo fix to add template

public:
	MyAlgorithms(Test&);
	void Set(bool sorted = false);
	void bubbleSort(bool sorted = false);
	void selectionSort(bool sorted = false);
	void insertionSort(bool sorted = false);
	unsigned int partition(unsigned int, unsigned int, unsigned int);
	void recursiveQuickSort(unsigned int, unsigned int);
	void quickSort(bool sorted = false);
	void mergeSort(bool sorted = false);
	void shellSort(bool sorted = false);
	void binarySearch(bool sorted = false);
	void linearSearch(bool sorted = false);
	void heapSort(bool sorted = false);
};

#endif // MYALGORITHMS_H

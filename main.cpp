#include "MyAlgorithms.h"
using std::stoi;

int main(int argc, char* argv[])
{
	if (argc[1] == "string")
	{
		
	}
	else if (argc[1] == "int")
	{

	}
	else if (argc[1] == "unsigned int")
	{
		
	}
	else if (argc[1] == "long")
	{

	}
	else if (argc[1] == "unsigned long")
	{
		
	}
	unsigned int sizeOfList = stoi(argv[1]);
	Test<unsigned int> tester(sizeOfList);
	MyAlgorithms run;
	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
	// add average of sorting times
	// add fastest, slowest, fastest when sorted, and fastest when unsorted
	//
	run.selectionSort(tester.sorted);
	run.insertionSort(tester.sorted);
	run.quickSort(tester.sorted);
	run.mergeSort(tester.sorted);
	// shellSort(nums);
	// binarySearch(nums);
	// linearSearch(nums);
	// sorted list
	run.bubbleSort(true);
	run.selectionSort(true);
	run.insertionSort(true);
	run.quickSort(true);
	run.mergeSort(true);
	return 0;
}

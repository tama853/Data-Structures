#include "Test.h"
using std::stoi;

int main(int argc, char* argv[])
{
	// compile and enter in a size of the vector you would like to run the tests on

	unsigned int sizeOfList = stoi(argv[1]);
	Test<unsigned int> run(sizeOfList);

	// add full console menu to allow input to change types
	// todo add additional types to be sorted and timed
	//vector<string> strings;
	//vector<const char*> char;
	//vector<unsigned long long*> longPtr;
	//vector<floats> floats;
	//vector<objects> objects;
	
	// add average of sorting timeTest.hs
	// add fastest, slowest, fastest when sorted, and fastest when unsorted
	run.bubbleSort();
	run.selectionSort();
	run.insertionSort();
	run.quickSort();
	run.mergeSort();
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

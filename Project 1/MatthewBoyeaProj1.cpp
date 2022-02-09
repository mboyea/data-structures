/* This program compares the following five sort algorithms:
 * Heapsort, mergesort, quick sort, select sort, and insert sort
 * Author: Your Name
 * Date: 
 */

#include <algorithm>   // Provides swap
#include <cstdlib>     // Provides EXIT_SUCCESS, size_t
#include <iostream>    // Provides cout
#include <ctime>       // provide clock function.
using namespace std;
const size_t ARRAY_SIZE = 10000; 

// PROTOTYPES of the sorting functions used in this test program:
// Each of these functions has the same precondition and postcondition:
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
void heapsort(int data[ ], size_t n);
void mergesort(int data[ ], size_t n);
void quicksort(int data[], size_t n);
void selectionsort(int data[ ], size_t n);
void insertionsort(int data[], size_t n);

// PROTOTYPE of a function that will test one of the sorting functions:
void testsort(void sorter(int data[], size_t n), const char* name);


int main( )
{
	cout << "This program will generate arrays with ARRAY_SIZE elements" <<endl;
	cout << "Then it sorts the arrays by using different sort function and " << endl;
	cout << "displays the needed time for each sorting\n" << endl;
	cout << "Press Enter key to start test ";
	getchar();
	cout << endl;

    testsort(heapsort,      "heapsort"     );
	cout << "Press Enter key to continue ";
	getchar();
	cout << endl;

    testsort(mergesort,     "mergesort"    );
	cout << "Press Enter key to continue ";
	getchar();
	cout << endl;

    testsort(quicksort,     "quicksort"    );
	cout << "Press Enter key to continue ";
	getchar();
	cout << endl;

    testsort(selectionsort, "selectionsort");
	cout << "Press Enter key to continue ";
	getchar();
	cout << endl;


	testsort(insertionsort, "insertionsort");

	cout << "Press Enter key to exit ";
	getchar();

    return EXIT_SUCCESS;
}



void testsort(void sorter(int data[], size_t n), const char* name)
{
    const int    LIMIT      = 10000;    // Biggest number to put in the array
    int data[ARRAY_SIZE];              // Array of integers to be sorted
    size_t count[LIMIT];               // Count of how many times each
                                       // number appears in data array
    size_t i;                          // Index for the data array.

	clock_t beginning, ending;          // the beginning and ending time to call sorter function

    cout << "Testing the " << name << endl;
    
    // Initialize the count array to zeros:
    fill_n(count, LIMIT, (size_t)0);

    // Fill the data array with random numbers:
    srand(0);
    for (i = 0; i < ARRAY_SIZE; ++i)
    {
	data[i] = rand( ) % (LIMIT);
        ++count[data[i]];
    }
    
    // Sort the numbers
	beginning = clock();
    sorter(data, ARRAY_SIZE);
	ending = clock();

    // Check that the data array is sorted and that it has the right
    // number of copies of each number:
    --count[data[0]];
    for (i = 1; i < ARRAY_SIZE; ++i)
    {
	if (data[i-1] > data[i])
	{
	    cout << "Incorrect sort at index " << i << endl;
	    return;
	}
	--count[data[i]];
    }
    
    for (i = 0; i < (size_t) LIMIT; ++i)
    {
	if (count[i] != 0)
	{
	    cout << "Incorrect numbers in the data array after sorting."
		 << endl;
	    return;
	}
    }


    cout << "Sorting completed correctly ";
	cout << "in " << (ending - beginning)/1000.0 << " seconds\n" << endl;
}



//*************************************************************************
// HEAPSORT IMPLEMENTATION:
// Assume that the heap data stored in array. i.e. we view the array as heap
size_t parent(size_t k)
{
    
}

size_t left_child(size_t k)
{
    
}

size_t right_child(size_t k)
{
    
}

// make a heap based on given data array
void make_heap(int data[ ], size_t n)
{
    
}

void reheapify_down(int data[ ], size_t n)
{
   
}

void heapsort(int data[ ], size_t n)
{
    
}
//*************************************************************************



//*************************************************************************
// MERGESORT IMPLEMENTATION:
//
void merge(int data[ ], size_t n1, size_t n2)
// Precondition: data is an array (or subarray) with at least n1 + n2 elements.
// The first n1 elements (from data[0] to data[n1 - 1]) are sorted from
// smallest to largest, and the last n2 (from data[n1] to data[n1 + n2 - 1])
// also are sorted from smallest to largest.
// Postcondition: The first n1 + n2 elements of data have been rearranged to be
// sorted from smallest to largest.
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
{
   
}

void mergesort(int data[ ], size_t n)
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, thenbad_alloc is thrown.
// Library facilities used: cstdlib
{
   
}
//*************************************************************************



//*************************************************************************
// QUICKSORT IMPLEMENTATION:
//
//*************************************************************************

size_t partition(int data[], size_t n)
{
	
}

void quicksort(int data[], size_t n)
{
	
}


//*************************************************************************
// SELECTIONSORT IMPLEMENTATION:
//
void selectionsort(int data[ ], size_t n)
// Library facilities used: algorithm, cstdlib
{
  
}
//*************************************************************************

//*************************************************************************
// INSERTION SORT IMPLEMENTATION
//
void insertionsort(int data[], size_t n)
// 
{
	
}







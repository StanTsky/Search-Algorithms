/*
--------------------------------------------------------------------
* Name:       Stan Turovsky
* Class:      Advanced C++
* Files:      main.cpp
* Purpose:    Demonstration of linear, sorted, and binary search 
*             algorithms
--------------------------------------------------------------------
*/

#include <iostream>
#include <ctime>
using namespace std;

// Global variables (JUST THIS ONCE)
long linearCount = 0;
long sortedCount = 0;
long binaryCount = 0;

int linearSearch(int numbers[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		linearCount++;
		if (numbers[i] == key)
			return i;
	}
	return -1;
}

void bubblesort(int numbers[], int size)  // array bubble sort
{
	for (int pass = 0; pass < size; pass++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				int temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
		}
	}
}

void display(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";
	cout << endl;
}

int sortedSearch(int numbers[], int size, int key)
{
	int i = 0;
	while (i < size && numbers[i] <= key)
	{
		sortedCount++;
		if (numbers[i] == key)
			return i;
		i++;
	}
	return -1;
}

int binarySearch(int numbers[], int size, int key) // binary search
{
	int begin = 0;
	int end = size - 1;

	while (begin <= end)
	{
		binaryCount++;
		int middle = (begin + end) / 2;
		if (numbers[middle] == key)
			return middle;
		else if (key < numbers[middle])
			end = middle - 1;
		else
			begin = middle + 1;
	}
	return -1;
}

int main()
{
	const int NUM_SEARCHES = 5;
	const int SIZE = 100;
	int numbers[SIZE];
	int searchKeys[NUM_SEARCHES];

	srand(time(0));
	for (int i = 0; i < SIZE; i++)
		numbers[i] = rand() % (SIZE * 5);     // fills the numbers array

	for (int i = 0; i < NUM_SEARCHES; i++)
		searchKeys[i] = rand() % (SIZE * 5);  // fills the search keys array

  cout << "Initial numbers array..." << endl;
  display(numbers, SIZE);       // show the numbers array

	// Linear search test
  cout << "Linear search in progress..." << endl;
	for (int i = 0; i < NUM_SEARCHES; i++)
	{
		int index = linearSearch(numbers, SIZE, searchKeys[i]);

		if (index == -1)
			cout << "Search key " << searchKeys[i] << " not found." << endl;
		else
			cout << "Search key " << searchKeys[i] << " found at index " << index << "." << endl;
	}
	bubblesort(numbers, SIZE);    // bubble sort numbers array
  cout << "Array bubble sort result..." << endl;
	display(numbers, SIZE);       // show the numbers array

	// Sorted search test
  cout << "Bubble sorted array search in progress..." << endl;
	for (int i = 0; i < NUM_SEARCHES; i++)
	{
		int index = sortedSearch(numbers, SIZE, searchKeys[i]);

		if (index == -1)
			cout << "Search key " << searchKeys[i] << " not found." << endl;
		else
			cout << "Search key " << searchKeys[i] << " found at index " << index << "." << endl;
	}

	// Binary search test
	for (int i = 0; i < NUM_SEARCHES; i++)
	{
		int index = binarySearch(numbers, SIZE, searchKeys[i]);

		if (index == -1)
			cout << "Search key " << searchKeys[i] << " not found." << endl;
		else
			cout << "Search key " << searchKeys[i] << " found at index " << index << "." << endl;
	}

	cout << endl << "SUMMARY:" << endl;
	cout << "Linear search comparisons: " << linearCount << endl;
	cout << "Sorted search comparisons: " << sortedCount << endl;
	cout << "Binary search comparisons: " << binaryCount << endl;

	// keep this stuff at the end of main
	cout << endl;
	//system("pause");
	return 0;
}
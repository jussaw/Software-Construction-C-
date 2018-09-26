/*
 * Justin Sawyer
 * jts0047
 * hw3.cpp
 * To compile I just ran "g++ -o hw4 hw4.cpp" in Terminal on my Linux machine.
 *
 * I referenced the slides from class.
 * I used this to help me pass an array by reference https://goo.gl/3buO3K.
 * I used this to help me read and write files https://youtu.be/Iho2EdJgusQ.
 */

// Importing Libraries
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

// Global Variables
string firstInputFile, secondInputFile, outFileName;
ifstream inFile1, inFile2;
ofstream outFile;
int inArray1_size, inArray2_size, sortedArray_size;
const int MAX_SIZE1 = 1000, MAX_SIZE2 = 2000;
int inArray1[MAX_SIZE1], inArray2[MAX_SIZE1], sortedArray[MAX_SIZE2];

// Headers for Functions.
int readFile(int (&inputArray)[MAX_SIZE1], ifstream& inFile);
void test_readFile(void);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[],
		 int inputArray2_size);
void test_sort(void);
void writeFile(int outputArray[], int outputArray_size);

int main()
{
	// Asks for, and receives, the first file name.
	cout << "*** Welome to Justin's sorting Program ***" << endl
		 << "Enter the first input file name: ";
	cin >> firstInputFile;

	// Opens first file.
	inFile1.open(firstInputFile);

	// Check for error
	if (inFile1.fail())
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	// Reads first file and sets size of array, then closes file.
	inArray1_size = readFile(inArray1, inFile1);
	inFile1.close();

	// Lists how many numbers are in the first file, the lists numbers.
	cout << "The list of " << inArray1_size << " numbers in file "
		 << firstInputFile << " is:" << endl;
	for (int i = 0; i < inArray1_size; i++)
	{
		cout << inArray1[i] << endl;
	}
	cout << endl;

	// Asks for, and receives, the second file name.
	cout << "Enter the second input file name: ";
	cin >> secondInputFile;

	// Opens the second file.
	inFile2.open(secondInputFile);

	// Check for error
	if (inFile2.fail())
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	// Reads and closes file.
	inArray2_size = readFile(inArray2, inFile2);
	inFile2.close();

	// Lists how many numbers are in the second file, the lists numbers.
	cout << "The list of " << inArray2_size << " numbers in file "
		 << secondInputFile << " is:" << endl;
	for (int i = 0; i < inArray2_size; i++)
	{
		cout << inArray2[i] << endl;
	}
	cout << endl;

	// Sorts the two arrays to a new array, then prints the sorted numbers.
	sortedArray_size = sort(inArray1, inArray1_size, inArray2, inArray2_size);
	cout << "The sorted list of " << sortedArray_size << " numbers is: ";
	for (int i = 0; i < sortedArray_size; i++)
	{
		cout << sortedArray[i] << " ";
	}
	cout << endl;

	cout << "Enter the output file name: ";
	cin >> outFileName;
	writeFile(sortedArray, sortedArray_size);
	cout << "*** Please check the new file - " << outFileName << " ***"
		 << endl << "*** Goodbye. ***" << endl;

	return 0;
}

// Takes in a reference int array and ifstream object, and returns the number
// of items in the the array it creates from reading a file.
int readFile(int (&inputArray)[MAX_SIZE1], ifstream& inFile)
{
	int i = 0;
	while (!inFile.eof())
	{
		inFile >> inputArray[i];
		i++;
	}
	return i;
}

// Test for readFile.
void test_readFile(void)
{
	int arr1[MAX_SIZE1];
	ifstream inpFile1("readtest1.txt");
	cout << "test_readFile Case 1:" << endl;
	assert(243 == readFile(arr1, inpFile1));
	inpFile1.close();
	cout << "\tCase 1 passed.";

	int arr2[MAX_SIZE1];
	ifstream inpFile2("readtest2.txt");
	cout << "test_readFile Case 2:" << endl;
	assert(206 == readFile(arr2, inpFile2));
	inpFile2.close()
	;cout << "\tCase 2 passed.";

	int arr3[MAX_SIZE1];
	ifstream inpFile3("readtest3.txt");
	cout << "test_readFile Case 3:" << endl;
	assert(176 == readFile(arr3, inpFile3));
	inpFile3.close();
	cout << "\tCase 3 passed.";
}

// Merge sorts two sorted int arrays, then returns size of new array.
int sort(int inputArray1[], int inputArray1_size, int inputArray2[],
		 int inputArray2_size)
{
	// i is pointer for intputArray1
	// j is pointer for intputArray2
	// k represents size of sortedArray
	int i = 0, j = 0, k = 0;

	while(i < inputArray1_size && j < inputArray2_size)
	{
		if (inputArray1[i] <= inputArray2[j])
		{
			sortedArray[k] = inputArray1[i];
			i++;
		}
		else
		{
			sortedArray[k] = inputArray2[j];
			j++;
		}
		k++;
	}
	if (i < inputArray1_size)
	{
		for (int p = i; p < inputArray1_size; p++)
		{
			sortedArray[k] = inputArray1[p];
			k++;
		}
	}
	else
	{
		for (int p = j; p < inputArray2_size; p++)
		{
			sortedArray[k] = inputArray2[p];
			k++;
		}
	}

	return k;
}

// Test for sort().
void test_sort(void)
{
	int arr1[5] = {0,4,5,8,10};
	int arr2[5] = {2,4,6,12,13};
	int arr12[10] = {0,2,4,4,5,6,8,10,12,13};

	cout << "test_sort Case 1:" << endl;
	assert(10 == sort(arr1, 5, arr2, 5));
	for (int i = 0; i < 10; i++)
	{
		assert (sortedArray[i] == arr12[i]);
	}
	cout << "\tCase 1 passed" << endl;

	int arr3[5] = {1,3,4,6,8};
	int arr4[5] = {0,2,5,6,9};
	int arr34[10] = {0,1,2,3,4,5,6,6,8,9};

	cout << "test_sort Case 2:" << endl;
	assert(10 == sort(arr3, 5, arr4, 5));
	for (int i = 0; i < 10; i++)
	{
		assert (sortedArray[i] == arr34[i]);
	}
	cout << "\tCase 2 passed" << endl;

	int arr5[5] = {12,13,26,58,85};
	int arr6[5] = {5,15,35,55,70};
	int arr56[10] = {5,12,13,15,26,35,55,58,70,85};

	cout << "test_sort Case 2:" << endl;
	assert(10 == sort(arr5, 5, arr6, 5));
	for (int i = 0; i < 10; i++)
	{	
		assert (sortedArray[i] == arr56[i]);
	}
	cout << "\tCase 3 passed" << endl;
}

// Takes in an int array and the array size, and writes the ints in a file.
void writeFile(int outputArray[], int outputArray_size)
{
	outFile.open(outFileName);
	for (int i = 0; i < sortedArray_size; i++)
	{
		outFile << sortedArray[i] << endl;
	}
	outFile.close();
}

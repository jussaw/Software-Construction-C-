#include <cstdlib>
#include <iostream>
using namespace std;





int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size);

int sortedArray[2000];

int main()
{
	int arr1[5], arr2[5];
	int size = 5;
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		arr1[i] = j;
		j += 2;
	}
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		arr2[i] = k;
		k += 2;
	}
	int sortSize = sort(arr1, size, arr2, size);

	for (int i = 0; i < sortSize; i++)
	{
		cout << sortedArray[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}
}


int sort(int inputArray1[], int inputArray1_size, int inputArray2[],
		 int inputArray2_size)
{
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
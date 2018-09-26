
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int main()
{
	char filename[50];
	ifstream file;
	cin.getline(filename, 50);
	file.open(filename);

	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}

	char word[50];
	file >> word;
	while(file.good())
	{
		cout << word << " ";
		bucky >> word;
	}

	return 0;
}
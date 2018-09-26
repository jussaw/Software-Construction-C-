
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));

	string outFileName;
	int i, k;

	cout << "Type file name to be printed to: ";
	cin >> outFileName;
	cout << "What number to start at: ";
	cin >> i;
	//cout << "What number to iterate through: ";
	//cin >> k;



	ofstream outFile;
	outFile.open(outFileName);
	
	while (i < 1000)
	{
		k = (((double)rand()/(double)RAND_MAX)) * 10;
		outFile << i << endl;
		i += k;
	}
	outFile.close();
}
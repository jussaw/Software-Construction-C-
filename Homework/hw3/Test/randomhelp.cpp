/*
 * Justin Sawyer
 * jts0047
 * hw3.cpp
 * To compile I just ran g++ -o hw3 hw3.cpp.
 *
 *
 *
 */

// Imoprting libraries.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	/*double random_number = ((double) rand() / (RAND_MAX));

	cout << random_number << endl;
	cout << (double) 1/3 << endl;*/

	for (int i = 0; i < 10; i++)
	{
		cout << ((double)rand()/(double)RAND_MAX) << endl;
	}

	return 0;
}
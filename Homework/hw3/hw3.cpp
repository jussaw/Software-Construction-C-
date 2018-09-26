/*
 * Justin Sawyer
 * jts0047
 * hw3.cpp
 * To compile I just ran "g++ -o hw3 hw3.cpp" in Terminal on my Linux machine.
 *
 * I referenced the slides from class.
 * I used this to help me generate a random number https://goo.gl/io4KpJ.
 */

// Imoprting libraries.
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

// Declaring functions.
bool at_least_two_alive(bool, bool, bool);
void Aaron_shoots1 (bool&, bool&);
void Bob_shoots (bool&, bool&);
void Charlie_shoots (bool&, bool&);
void Aaron_shoots2 (bool&, bool&);
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

// Declaring variables
double randomNumber;
const double AARON_PROBABILITY = (double) 1/3,
			 BOB_PROBABILITY = (double) 1/2,
			 CHARLIE_PROBABILITY = (double) 1;
const int TOTAL_RUNS = 10000, CASE_SPACE = 8, CASE2_SPACE = 16;
bool aaronAlive = true, bobAlive = true, charlieAlive = true;

// Main function.
int main()
{
	// Sets format for decimal numbers.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Sets new seed for random time.
	srand(time(0));

	cout << "*** Welcome to Justin’s Duel Simulator ***" << endl;

	// Calls test for at_least_two_alive();
	test_at_least_two_alive();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout <<  endl;
	
	// Calls test for Aaron_shoots1();
	test_Aaron_shoots1();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout <<  endl;

	// Calls test for Bob_shoots();
	test_Bob_shoots();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout <<  endl;

	// Calls test for Charlie_shoots();
	test_Charlie_shoots();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout <<  endl;

	// Calls test for Aaron_shoots2();
	test_Aaron_shoots2();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout <<  endl;

	// Asks user to initiate test for strategy 1.
	cout << "Press ready to test strategy 1 (run 10000 times):";
	cin.ignore().get();
	cout << "Press any key to continue...";
	cin.ignore().get();
	cout << "\n...\n...\n...\n";

	// Initiates strategy 1.
	int aWins = 0, bWins = 0, cWins = 0;
	for(int i = 0; i < TOTAL_RUNS; i++)
	{
		bool A_alive = true, B_alive = true, C_alive = true;
		while (at_least_two_alive(A_alive, B_alive, C_alive))
		{
			if (A_alive)
			{
				Aaron_shoots1(B_alive, C_alive);	
			}
			if (B_alive)
			{
				Bob_shoots(A_alive, C_alive);
			}
			if (C_alive)
			{
				Charlie_shoots(A_alive, B_alive);
			}

		}

		if (A_alive)
		{
			aWins++;
		}
		if (B_alive)
		{
			bWins++;
		}
		if (C_alive)
		{
			cWins++;
		}
	}

	// Prints how many duels each person won in strategy 1.
	cout << endl << "Aaron won " << aWins << "/" << "10000 duels or " 
		 << (double)aWins/100 << "%" << endl;
	cout << "Bob won " << bWins << "/" << "10000 duels or "
		 << (double)bWins/100 << "%" << endl;
	cout << "Charlie won " << cWins << "/" << "10000 duels or "
		 << (double)cWins/100 << "%" << endl << endl;

	// Asks user to initiate strategy 2.
	cout << "Press ready to test strategy 2 (run 10000 times):" << endl
		 << "Press any key to continue...";
	cin.ignore().get();
	cout << "\n...\n...\n...\n";

	// Initiates strategy 2.
	int aWins2= 0, bWins2 = 0, cWins2 = 0;
	for (int i = 0; i < TOTAL_RUNS; i++)
	{
		bool A_alive = true, B_alive = true, C_alive = true;
		Bob_shoots(A_alive, C_alive);
		if (C_alive)
		{
			Charlie_shoots(A_alive, B_alive);
		}
		while (at_least_two_alive(A_alive, B_alive, C_alive))
		{
			if (A_alive)
			{
				Aaron_shoots1(B_alive, C_alive);	
			}
			if (B_alive)
			{
				Bob_shoots(A_alive, C_alive);
			}
			if (C_alive)
			{
				Charlie_shoots(A_alive, B_alive);
			}
		}
		if (A_alive)
		{
			aWins2++;
		}
		if (B_alive)
		{
			bWins2++;
		}
		if (C_alive)
		{
			cWins2++;
		}
	}

	// Prints how many duels each person won in strategy 1.
	cout << endl << "Aaron won " << aWins2 << "/" << "10000 duels or " 
		 << (double)aWins2/100 << "%" << endl;
	cout << "Bob won " << bWins2 << "/" << "10000 duels or "
		 << (double)bWins2/100 << "%" << endl;
	cout << "Charlie won " << cWins2 << "/" << "10000 duels or "
		 << (double)cWins2/100 << "%" << endl << endl;

	// Checks and prints which strategy is better for Aaron.
	if (aWins2 > aWins)
	{
		cout << "Strategy 2 is better than strategy 1." << endl;
	}
	else 
	{

		cout << "Strategy 1 is better than strategy 2." << endl;
	}

	return 0;
}

// Checks if at least two people are still alive.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
	int lives = 0;

	// Checks if Aaron is alive or dead, and adds one to lives if alive.
	if (A_alive)
	{
		lives++;
	}

	// Checks if Bob is alive or dead, and adds one to lives if alive.
	if (B_alive)
	{
		lives++;
	}

	// Checks if Charlie is alive or dead, and adds one to lives if alive.
	if (C_alive)
	{
		lives++;
	}

	// Return true if two are alive, otherwise return false.
	if (lives > 1)
	{
		return true;
	}
	return false;

}

// Aaron will shoot at the best marksman. First he checks if Charlie is
// still alive then shoots at him if so. If not then he shoots at Bob.
void Aaron_shoots1 (bool& B_alive, bool& C_alive)
{
	// Charlie is alive, then Aaron will shoot at Charlie.
	if (C_alive)
	{
		randomNumber = ((double) rand() / (RAND_MAX));

		// Aaron kills Charlie if randomNumber is less that Aaron's probability
		// of hitting. If not, Aaron misses.
		if (randomNumber <= AARON_PROBABILITY)
		{
			C_alive = false;
		}
	}

	// Else statement is for if Charlie is already dead, then Aaron will
	// shoot at Bob.
	else
	{
		randomNumber = ((double) rand() / (RAND_MAX));

		// Aaron kills Bob if randomNumber is less than Aaron's probability.
		// of hitting. If not, Aaron misses
		if (randomNumber <= AARON_PROBABILITY)
		{
			B_alive = false;
		}
	}
}

// Bob checks if Charlie is still alive and shoots at Charlie, if not
// he shoots at Aaron.
void Bob_shoots(bool& A_alive, bool& C_alive)
{
	if (C_alive)
	{
		randomNumber = ((double)rand()/(double)RAND_MAX);

		// Bob kills Charlie if randomNumber is less than Bob's probability
		// of hitting. If not , Bob misses
		if (randomNumber <= BOB_PROBABILITY)
		{
			C_alive = false;
			charlieAlive = false;
		}
	}

	// Else statement is for if Charlie is already dead, the Bob will shoot at Aaron
	else
	{
		randomNumber = randomNumber = ((double)rand()/(double)RAND_MAX);

		// Bob kills Aaron if randomNumber is less than Aaron's probability
		// of hitting. If not, Bob misses
		if (randomNumber <= BOB_PROBABILITY)
		{
			A_alive = false;
			aaronAlive = false;
		}
	}
}

// Charlie checks if Bob is still alive and shoots at Bob, if not
// he shoots at Aaron.
void Charlie_shoots (bool& A_alive, bool& B_alive)
{	
	// If Bob is still alive then Charlie kills Bob, since he will always hit.
	if (B_alive)
	{
		B_alive = false;
		bobAlive = false;
	}

	//If Bob is dead then Charlie kills Aaron, since he will always hit.
	else
	{
		A_alive = false;
		aaronAlive = false;
	}
}

// Strategy 2 for Aaron. Aaron will purposefully miss his first shot, then
// on his second round he will shoot.
void Aaron_shoots2 (bool& B_alive, bool& C_alive)
{
	B_alive = bobAlive;
	C_alive = charlieAlive;
	cout << "Aaron intentionally misses his first shot";
https://www.google.com/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=string+in+c%2B%2B&*
	do
	{
		Bob_shoots(aaronAlive, charlieAlive);
		Charlie_shoots(aaronAlive, bobAlive);
		Aaron_shoots1(bobAlive, charlieAlive);
	} while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive));
}

// Test for at_least_two_alive, with all 8 different scenarios.
void test_at_least_two_alive(void)
{
	cout << "Unit Testing 1: Function – at_least_two_alive()\n";
	cout << setw(CASE_SPACE) << " " << "Case 1: Aaron alive, Bob alive, "
		 << "Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;

	cout << setw(CASE_SPACE) << " " << "Case 2: Aaron dead, Bob alive, "
		 << "Charlie alive\n";
	assert(true== at_least_two_alive(false, true, true));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;

	cout << setw(CASE_SPACE) << " " << "Case 3: Aaron alive, Bob dead, "
		 << "Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;
	
	cout << setw(CASE_SPACE) << " " << "Case 4: Aaron alive, Bob alive, "
		 << "Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;

	cout << setw(CASE_SPACE) << " " << "Case 5: Aaron dead, Bob dead, "
		 << "Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;

	cout << setw(CASE_SPACE) << " " << "Case 6: Aaron dead, Bob alive, "
		 << "Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;
	
	cout << setw(CASE_SPACE) << " " << "Case 7: Aaron alive, Bob dead, "
		 << "Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;
	
	cout << setw(CASE_SPACE) << " " << "Case 8: Aaron dead, Bob dead, "
		 << "Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << setw(CASE_SPACE) << " " << "Case passed ..." << endl;}

// Test for Aaron_shoots1 with all three different scenarios.
void test_Aaron_shoots1(void)
{
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive,Charlie_alive)" 
		 << endl;
	bool B_alive = true, C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 1: Bob alive, Charlie alive" << endl;
	cout << setw(CASE2_SPACE) << " " << "Aaron is shooting at Charlie "
		 << endl;

	Aaron_shoots1(B_alive, C_alive);
	if (C_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Aaron misses." << endl;
	}
	else
	{

		cout << setw(CASE2_SPACE) << " " << "Charlie is dead." << endl;
	}


	B_alive = false, C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 2: Bob dead, Charlie alive" << endl;
	cout << setw(CASE2_SPACE) << " " << "Aaron is shooting at Charlie "
		 << endl;
	Aaron_shoots1(B_alive, C_alive);
	if (C_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Aaron misses." << endl;
	}
	else
	{

		cout << setw(CASE2_SPACE) << " " << "Charlie is dead." << endl;
	}


	B_alive = true, C_alive = false;
	cout << setw(CASE_SPACE) << " " << "Case 3: Bob alive, Charlie dead" << endl;
	cout << setw(CASE2_SPACE) << " " << "Aaron is shooting at Bob "
		 << endl;
	Aaron_shoots1(B_alive, C_alive);
	if (B_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Aaron misses." << endl;
	}
	else
	{

		cout << setw(CASE2_SPACE) << " " << "Bob is dead." << endl;
	}

}

// Test for Bob_shoots with all three different scenarios.
void test_Bob_shoots(void)
{
	//Case 1
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)"
		 << endl;

	bool A_alive = true, C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 1: Aaron alive, Charlie alive"
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Bob is shooting at Charlie "
			 << endl;
	Bob_shoots(A_alive, C_alive);
	if (C_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Bob misses." << endl;
	}
	else
	{

		cout << setw(CASE2_SPACE) << " " << "Charlie is dead." << endl;
	}

	//Case 2
	A_alive = false, C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 2: Aaron dead, Charlie alive"
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Bob is shooting at Charlie "
			 << endl;
	Bob_shoots(A_alive, C_alive);
	if (C_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Bob misses." << endl;
	}
	else
	{
		cout << setw(CASE2_SPACE) << " " << "Charlie is dead." << endl;
	}

	//Case 3
	A_alive = true, C_alive = false;
	cout << setw(CASE_SPACE) << " " << "Case 3: Aaron alive, Charlie dead"
		 << endl;

	cout << setw(CASE2_SPACE) << " " <<"Bob is shooting at Aaron "<< endl;
	Bob_shoots(A_alive, C_alive);
	if (A_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Bob misses." << endl;
	}
	else
	{
		cout << setw(CASE2_SPACE) << " " << "Aaron is dead." << endl;
	}
}

// Test for Charlie_shoots with all three different scenarios.
void test_Charlie_shoots(void)
{
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)"
		 << endl;

	bool A_alive = true, B_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 1: Aaron alive, Bob alive"
	     << endl;
	cout << setw(CASE2_SPACE) << " " << "Charlie is shooting at Bob "
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Bob is dead." << endl;
	Charlie_shoots(A_alive, B_alive);

	A_alive = false, B_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 2: Aaron dead, Bob alive"
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Charlie is shooting at Bob "
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Bob is dead." << endl;
	Charlie_shoots(A_alive, B_alive);

	A_alive = true, B_alive = false;
	cout << setw(CASE_SPACE) << " " << "Case 2: Aaron alive, Bob dead"
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Charlie is shooting at Aaron "
		 << endl;
	cout << setw(CASE2_SPACE) << " " << "Aaron is dead." << endl;
	Charlie_shoots(A_alive, B_alive);

}

// Test for Aaron_shoots2 with all three different scenarios.
void test_Aaron_shoots2(void)
{
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)"
		 << endl;
	bool B_alive = true, C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 1: Bob alive, Charlie alive" 
		 << endl
		 << setw(CASE2_SPACE) << " " << "Aaron intentionally misses his "
		 << "first shot" << endl
		 << setw(CASE2_SPACE) << " " << "Both Bob and Charlie are alive." 
		 << endl;

	B_alive = false; C_alive = true;
	cout << setw(CASE_SPACE) << " " << "Case 2: Bob dead, Charlie alive" 
		 << endl
		 << setw(CASE2_SPACE) << " " << "Aaron is shooting at Charlie"
		 << endl;
	Aaron_shoots1(B_alive, C_alive);
	if (C_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Charlie is alive." << endl;
	}
	else
	{
		cout << setw(CASE2_SPACE) << " " << "Charlie is dead." << endl;
	}

	B_alive = true; C_alive = false;
	cout << setw(CASE_SPACE) << " " << "Case 2: Bob alive, Charlie dead" 
		 << endl
		 << setw(CASE2_SPACE) << " " << "Aaron is shooting at Bob"
		 << endl;
	Aaron_shoots1(B_alive, C_alive);
	if (B_alive)
	{
		cout << setw(CASE2_SPACE) << " " << "Bob is alive." << endl;
	}
	else
	{
		cout << setw(CASE2_SPACE) << " " << "Bob is dead." << endl;
	}
}
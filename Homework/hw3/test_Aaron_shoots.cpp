/*
 * COMP2710: Homework 3
 * This program shows how to implement a test driver.
 *
 *
 */ 
# include <iostream>
# include<ctime>
using namespace std;

//prototypes
void Aaron_shoots (bool&, bool&); //function to simulate Aaron shot
void test_Aaron_shoots (); //function to simulate Aaron shot

int main() {

  test_Aaron_shoots();
  
  //call other test drivers here
  ...

  return 0;
}

//How to test Aaron_shoots
void test_Aaron_shoots(void) {
    bool B_alive;
	bool C_alive;

	B_alive = true;
	C_alive = true;
	Aaron_shoots(B_alive, C_alive);

	B_alive = true;
	C_alive = false;
	Aaron_shoots(B_alive, C_alive);

	B_alive = false;
	C_alive = true;
	Aaron_shoots(B_alive, C_alive);

//	B_alive = false;
//	C_alive = false;
//	Aaron_shoots(B_alive, C_alive);

	return 0;
}

void Aaron_shoots (bool& Bob_alive, bool& Charlie_alive)
{
	// determine if the person hit his target
	int percentageShot = rand()%100;

	//check input arguments
	assert(Bob_alive || Charlie_alive);

	cout<<"Aaron is shooting ";

	// assure that the first parameter is the
    // person with the highest percentage shot
	if (Charlie_alive)
	{
		cout<<"Aaron is shooting at Charlie.\n";
		// determine if it is a hit based on the
        // percentage given in the problem and
		// set that person dead by setting
        // Charlie_alive to false
		 ...
	}
	else if (Bob_alive)
	{
		cout<<"Aaron is shooting at Bob.\n";
		// determine if it is a hit based on the
        // percentage given in the problem and
		// set that person dead by setting
        // Bob_alive to false
		...
	}
}

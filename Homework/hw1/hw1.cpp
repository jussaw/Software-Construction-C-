/*
 * Justin Sawyer
 * jts0047
 * hw1.cpp
 * I just used the pdf file for the homework, and the slides from lecture.
 * I compiled by using "g++ -o hw1 hw1.cpp" then "./hw1" on my Linux machine.
 */

#include <iostream>
using namespace std;

int main()
{
	//Declaring Fields
	double lethalDoseMouse, lethalDoseDieter, mouseWeight, dieterWeight;
	int safeSodaAmount;
	const double AMOUNT_SWEETENER_IN_CAN = .001;


	//Prompts user for lethal dose of artificial sweetener
	cout << "What is the amount of artificial sweetener needed to kill a mouse:\n";
	cin >> lethalDoseMouse;

	//Prompts user for weight of mouse
	cout << "\nWhat is the weight of the mouse: ";
	cin >> mouseWeight;

	//Prompts user for weigt of dieter
	cout << "\nWhat is the weight of the dieter: ";
	cin >> dieterWeight;

	//Calculates the lethal rate of artificial sweetener
	const double LETHAL_RATE = lethalDoseMouse / mouseWeight;
	lethalDoseDieter = LETHAL_RATE * dieterWeight;

	//Calculates the amount of soda dieter can drink safely
	safeSodaAmount = lethalDoseDieter / AMOUNT_SWEETENER_IN_CAN;

	//Tells user how many cans dieter can drink
	cout << "\nYou can drink " << safeSodaAmount << " diet soda cans without"
		<< " dying as a result.\n";
	return 0;
}
/*
 * Justin Sawyer
 * jts0047
 * hw2.cpp
 * To compile I just ran g++ -o hw2 hw2.cpp.
 *
 * Used this link to help with formatting table https://goo.gl/lbWG1C.
 * Used the lecture slides.
 */

#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
	// Declares variables.
	double loanAmount, interestRate, monthlyPayments, balance, payment,
		principal, interest, monthlyInterestRate, totalInterest = 0;
	int month = 0;
	const int TITLE_WIDTH = 9, BODY_WIDTH = 8;

	// Sets number format to "number" format ith two decimal places (00.00).
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do
	{
		// Asks for and receives loan amount, interest rate, and monthly
		// payments.
		cout << "Loan Amount: ";
		cin >> loanAmount;
		cout << "Interest Rate (% per year): ";
		cin >> interestRate;
		cout << "Monthly Payments: ";
		cin >> monthlyPayments;
		cout << "\n";

		// Sets balance, payment, interest, and interest.
		balance = loanAmount;
		payment = monthlyPayments;
		monthlyInterestRate = interestRate / 12;
		interest = balance * (monthlyInterestRate / 100);

		// Gives error to user if payment will not cover the first months
		// debt.
		if (interest > payment)
		{
			cout << "******************************************************"
				 << endl
			     << "You're payment plan will not work with "
				 << "the given information.\n"
				 << "Please type a lower loan amount, lower interest rate, "
				 << "or higher \nmonthly payments.\n"
			     << "******************************************************"
			     << endl << endl;
		}

	} while (interest > payment);


	// Prints the beginning of the Amortization Table.
	cout << "******************************************************"
	     << "\n\tAmortization Table"
	     << "\n******************************************************"
	     << left << setw(TITLE_WIDTH) << "\nMonth"
	     << left << setw(TITLE_WIDTH) << "Balance"
	     << left << setw(TITLE_WIDTH) << "Payment"
	     << left << setw(TITLE_WIDTH) << "Rate"
	     << left << setw(TITLE_WIDTH) << "Interest"
	     << left << setw(TITLE_WIDTH) << "Principal"
	     << endl
	     << left << setw(BODY_WIDTH) << "0" << "$"
	     << left << setw(BODY_WIDTH) << balance
	     << left << setw(TITLE_WIDTH) << "N/A"
	     << left << setw(TITLE_WIDTH) << "N/A"
	     << left << setw(TITLE_WIDTH) << "N/A"
	     << left << setw(TITLE_WIDTH) << "N/A"
	     << endl;


	// Write loop to calculate the month, balance, payment, rate, interest,
	// and pricipal while keeping aligned with table.
	while (balance > payment)
	{
		// Calculates, for every month, interest, principal, balance, month,
		// and total interest.
		interest = balance * (monthlyInterestRate / 100);
		principal = payment - interest;
		balance -= principal;
		month++;
		totalInterest += interest;

		// Prints the current month's month, balance, payment, rate, interest,
		// principal.
		cout << left << setw(BODY_WIDTH) << month << "$"
		     << left << setw(BODY_WIDTH) << balance << "$"
		     << left << setw(BODY_WIDTH) << payment;
		cout.precision(1);
		cout << left << setw(TITLE_WIDTH) << monthlyInterestRate << "$";
		cout.precision(2);
		cout << left << setw(BODY_WIDTH) << interest << "$"
		     << left << setw(BODY_WIDTH) << principal
		     << endl;

	}

	// Checks if there is more balance left, will change payment to cover rest
	// of balance, and finds new total interest. Then prints last month's line.
	if (balance > 0)

{		// Adds one to month, sets ayments to balance, interest, principal,
		// and sets balance to 0.
		month ++;
		principal = balance;
		interest = balance * (monthlyInterestRate / 100);
		payment = balance + interest;
		balance = 0;
		totalInterest += interest;

		//Prints last month line.
		cout << left << setw(BODY_WIDTH) << month << "$"
		     << left << setw(BODY_WIDTH) << balance << "$"
		     << left << setw(BODY_WIDTH) << payment;
		cout.precision(1);
		cout << left << setw(TITLE_WIDTH) << monthlyInterestRate << "$";
		cout.precision(2);
		cout << left << setw(BODY_WIDTH) << interest << "$"
		     << left << setw(BODY_WIDTH) << principal
		     << endl;
	}

	// Prints the ending of the Amortization Table.
	cout << "******************************************************" << endl
	     << "\nIt takes " << month << " months to pay off the loan."
	     << "\nTotal interest paid is : $" << totalInterest << "\n\n";

	return 0;
}

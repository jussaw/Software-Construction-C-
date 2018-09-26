/*
 * Justin Sawyer
 * jts0047
 * project2.cpp
 *
 * To compile I just ran "g++ -o project2 project2.cpp" in Terminal on my Linux machine.
 */

// Importing Libraries
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

// Class for User object. This is only used as an interface for other classes
class User
{
private: 
	// Variables for name and password of user
	string name, password;
public: 
	// Constructor
	User() {}

	// Function to return name of user
	string getName()
	{
		return name;
	}

	// Function to change name
	void setName(string nameIn)
	{
		name = nameIn;
	}

	// Function to change password
	void setPassword(string pwIn)
	{
		password = pwIn;
	}
};

class Client : public User
{
public:
	// This is to organize all items of the account of the client
	struct Account
	{
		int number, balance;
		string type;
	};

	// Variables for User class
	string employer;
	int ssn, income;
	vector<Account> accounts;

	// Functions
	bool confirm()
	{
		cout << "Client " << getName() << "'s information will be updated!"
			 << "\n1) Confirm" << "\n2) Cancel" << endl;
	}
};

class BranchEmployee : public User
{
public:
	// Constructor
	BranchEmployee() {}

	// Functions
	// add client function for program
	void addClient(Client clientIn)
	{

	}

	void addAccount(Client& clientIn)
	{

	}

	void editAccount(Client clientIn)
	{

	}
};

class Admin : public BranchEmployee
{
public:
	//Constructor
	Admin() {}

	//Functions
	void addBranch(BranchEmployee branchEmpIn)
	{

	}

	void deleteBranch(BranchEmployee branchEmpIn)
	{

	}

	void displayBranch()
	{

	}

};

class Menu
{
public:
	void setName(string nameIn);
	// Constructor
	Menu() {}

	// Functions
	// Menu that starts at the beginning of the program. 
	// Gives user to login or quit
	void runStartMenu()
	{
		cout << "\t==================================================" << endl
			 << "\t|  Welecome to the Auburn Branch of Tiger Bank!  |" << endl
			 << "\t==================================================" << endl
			 << "1) Login" << endl
			 << "2) Quit" << endl
			 << "\tPlease choose an option: ";
	}

	// Menu to ask user to sign in. Takes in a reference call to an object
	// of type user to store the login credentials
	void runLoginMenu(User& user)
	{
		cout << "\t==================================================" << endl
			 << "\t|   Login to Access the Teller Teminal System    |" << endl
			 << "\t==================================================" << endl;

		string name, password;
		cout << "User Name: ";
		cin >> name;
		user.setName(name);
		cout << "Password: ";
		cin >> password;
		user.setPassword(password);
	}

	// Menu for system administrator
	void runSysAdminMenu()
	{
		cout << "\t==================================================" << endl
			 << "\t| Teller Terminal System - System Administration |" << endl
			 << "\t==================================================" << endl
			 << "1) Client and Account Management" << endl
			 << "2) Add a branch staff member" << endl
			 << "3) Delete a branch staff member" << endl
			 << "4) Display branch staff" << endl
			 << "5) Change password" << endl
			 << "6) Exit" << endl
			 << "\tPlease choose an option: ";
	}

	// Menu for Branch staff
	void runBranchMenu()
	{
		cout << "\t==================================================" << endl
			 << "\t|      Teller Terminal System - Branch Staff     |" << endl
			 << "\t==================================================" << endl
			 << "1) Client and Account Management" << endl
			 << "2) Change password" << endl
			 << "3) Exit" << endl
			 << "\tPlease choose an option: ";
	}

	// Menu for account management
	void accountMgmtMenu()
	{
		cout << "\t==========================================================" << endl
			 << "\t| Teller Terminal System - Client and Account Management |" << endl
			 << "\t==========================================================" << endl
			 << "1) Add a client" << endl
			 << "2) Add an account" << endl
			 << "3) Edit Client Inormation" << endl
			 << "4) Manage an account" << endl
			 << "5) Save Client and Account Information" << endl
			 << "6) Exit" << endl
			 << "Please choose an option: ";
	}

};

class File 
{
	// Constructor
	File () {}

	// Functions
	vector<vector<string>> readFile(string fileName)
	{
		ifstream inFile(fileName);
		string 
	}

};

class System
{
public:
	// Fields
	Menu menu;
	User user;

	// Constructor
	System() {}

	// Functions
	void runSystem()
	{
		string outOfBoundsError = "Please retype an answer that is in bounds.\n";
		//cout << "hi" << endl;

		// Ask user if they want to login or quit. If they choose an answer
		// that is out of bounds then re ask them, if they choose 2, then end
		// the program.
		int startInput;
		do
		{
			menu.runStartMenu();
			cin >> startInput;
			if (startInput < 1 || startInput > 2)
			{
				cout << outOfBoundsError;
			}
		} while (startInput < 1 || startInput > 2);
		if (startInput == 2)
		{
			exit(1);
		}

		// Print login screen to user. 
		menu.runLoginMenu(user);

		

	}
};

int main()
{
	System system;
	system.runSystem();
	string name, password, employer, ssn, income
;
	return 0;
}
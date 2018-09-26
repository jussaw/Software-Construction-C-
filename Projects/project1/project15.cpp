/*
 * Justin Sawyer
 * jts0047
 * Project1.cpp
 *
 */
 
// Importing Libraries
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <vector>
using namespace std;
 
 
// Global variables
string highScoresFileStr = "high_scores_string.txt"; // name of file for string
string highScoresFileInt = "high_scores_int.txt"; // name of file for ints
 
class Puzzle
{
public:
	// Variables
	string question, answer1, answer2, answer3, answer4;
	int correctAnswer;
 
	// Constructor
	Puzzle(string questionIn, string answer1In, string answer2In,
		   string answer3In, string answer4In, int correctAnswerIn)
	{
		question = questionIn;
		answer1 = answer1In;
		answer2 = answer2In;
		answer3 = answer3In;
		answer4 = answer4In;
		correctAnswer = correctAnswerIn;
	}
 
	// Functions
	// Initializes some Puzzle objects and sotres them in a vector, then
	// return the vector
	vector<Puzzle> createPuzzles()
	{
		Puzzle puzzle1 = Puzzle("question", "answer0", "answer1", 
								   "answer2", "answer3", 0);
		Puzzle puzzle2 = Puzzle("question", "answer0", "answer1", 
								   "answer2", "answer3", 0);
		Puzzle puzzle3 = Puzzle("question", "answer0", "answer1", 
								   "answer2", "answer3", 0);
		Puzzle puzzle4 = Puzzle("question", "answer0", "answer1", 
								   "answer2", "answer3", 0);
		vector<Puzzle> puzzleVec = {puzzle1, puzzle2, puzzle3, puzzle4};
		return puzzleVec;
	}
 
	// Chooses a random puzzle from the vector in parameter and returns it
	Puzzle getPuzzles(vector<Puzzle> puzzleVecIn)
	{
		int randPuzzle = rand() % puzzleVecIn.size();
		return puzzleVecIn[randPuzzle];
	}
 
	// Returns true if user's answer mathces the correct answer of the Puzzle
	// object. Otherwise it return false
	bool checkCorrectAnswer(Puzzle puzzleIn, int answerIn)
	{
		if (answerIn == puzzleIn.correctAnswer)
			return true;
		return false;
	}
};
 
class Encounter
{
public:
	// Functions to be used in this class
	vector<Puzzle> createPuzzles();
	Puzzle getPuzzles(vector<Puzzle> puzzleVecIn);
 
	// Variables
 
 
	//Constructor
	Encounter(void);
 
	//Functions
	void runEncounter(Player &currentPlayer)
	{
		int randEncounter = rand() % 100;
		// 25% chance nothing happens
		if (randEncounter < 25)
		{
			// Nothing happens
		}
		if (randEncounter >= 25 && randEncounter < 50)
		{
			// INITIALIZE VECTOR OF PUZZLES WITH FUNCTIO
			// RUN PUZZLES
 
		}
		// 10% chance to encounter a professor. Lose 0-2 time, but gain 
		// 0-4 intelligence
		if (randEncounter >= 50 && randEncounter < 60)
		{
			int loss = rand() % 3, gain = rand() % 3;
			currentPlayer.time -= loss;
			currentPlayer.intelligence += gain;\
			cout << "You just encountered a professor. You lost " << loss
				 << " time, but gained " << gain << " intelligence" << endl;
		}
		// 10% chance to encounter a grad student. Lose 0-2 time
		if (randEncounter >= 60 && randEncounter < 70)
		{
			int loss = rand() % 3;
			currentPlayer.time -= loss;
			cout << "You just encountered a grad student. You lose " << loss
				 << " time." << endl;
 
		}
		// 15% chance to encounter grunt work. Lose 0-2 time and intelligence
		if (randEncounter >= 70 && randEncounter < 85)
		{
			int loss = rand() % 3, loss2 = rand() % 3;
			currentPlayer.time -= loss;
			currentPlayer.intelligence -= loss2;
			cout << "You just encountered grunt work. You lose " << loss
				 << " time and " << loss2 << " intelligence" << endl;
		}
		// 15% chance to encounter grade papers. Lose 0-2 time, but gain 
		// 0-4 money
		if (randEncounter >= 85 && randEncounter <= 100)
		{
			int loss = rand() % 3, gain = rand() % 5;
			currentPlayer.time -= loss;
			currentPlayer.money += gain;
			cout << "You just encountered grunt work. You lose " << loss
				 << " time, but gain " << gain << " intelligence" << endl;
		}
	}
};
 
class Player
{
public:
	// Variables
	string userName;
	int intelligence, time, money, score, steps;
	double randNum = rand() % 17 + 8; // Generates random number between 8 - 25.
 
	// Constructor
	Player()
	{
		intelligence = randNum;
		time = randNum;
		money = randNum;
	}
 
	// Functions
	void setName(string newUserName)
	{
		userName = newUserName;
	}
 
	int calculateScore()
	{
		score = intelligence * time * money;
		return score;
	}
 
	string calculateScoreString()
	{
		string scoreStr = to_string(score);
		return userName + " " + scoreStr;
	}
 
};
 
class Menu
{
public:
	// Declare Functions to use.
	void runEncounter(Player& currentPlayer);
	void runHighScore();
	bool checkIfHighScore (int userScore);
	void recordHighScore(int scoreIn, vector<int> scoresIn);
	vector<int> readFile1(string fileName);
	vector<string> readFile2(string fileName);
	void writeFile1(string fileName, vector<int> outputVec);
	void writeFile2(string fileName, vector<string> outputVec);
 
	// Variables
	string userName;
	Encounter encounter;
 
	// Constructor
	Menu(void);
 
	//Functions
	void runMainMenu(Player& currentPlayer)
	{
		int userInput;
		// Prompt user for name and change name in Player object
		cout << "What's your name?";
		cin >> userName;
		currentPlayer.setName(userName);
 
		// Print welcome message
		cout << "Welcome, " << currentPlayer.userName << endl;
 
		// While loop to run main menu
		bool continueGame = true;
		do
		{
			// Give user 3 options and take in an answer. Continue looping
			// until answer is in range
			bool answerBad = true;
			do
			{
				cout << "1) Start a New Game of Shelby Center and Dragons!"
					 << endl
					 << "2) View top 10 High Scores" << endl
					 << "3) Quit" << endl;
				cin >> userInput;
 
				// Checks if input is in bounds, if not, then will reloop
				if (userInput < 1 || userInput > 3)
				{
					cout << "Please retype an answer between 1-3." << endl;
					answerBad = true;
				}
				else
				{
					answerBad = false;
				}
 
			} while (answerBad);
			// Switch statement to execute user's input
			switch(userInput)
			{
				// Runs game
				case 1:
					runGameMenu(currentPlayer);
					break;
				// Shows high scores
				case 2:
					runHighScore();
					break;
				// Will quit game by ending loop
				case 3:
					continueGame = false;
					break;
			}
		} while (continueGame);
	}
 
	void runGameMenu(Player &currentPlayer)
	{
		currentPlayer.steps = 20;
		int userInput;
		// Do-while loop to continue running menu until score hits 0
		bool continueGame = true;
		do
		{
			// Do-while loop to keep asking user for input until answer is in
			// range
			bool answerBad = true;
			do
			{
				cout << "You are " << currentPlayer.steps << " steps away "
					 << "from the goal. Time left: " << currentPlayer.time
					 << endl
					 << "\n\t1) Move forward (takes time, could be risky...)"
					 << "\n\t2) Read technical papers (boost intelligence, "
					 << "takes time)"
					 << "\n\t3) Search for loose change (boost money, takes "
					 << "time)"
					 << "\n\t4) View character"
					 << "\n\t5) Quit the game"
					 << "\n\n\tPlease choose an action: ";
				cin >> userInput;
				// Checks if input is in bounds, if not, then will reloop
				if (userInput < 1 || userInput > 5)
				{
					cout << "Please retype an answer between 1-5." << endl;
					answerBad = true;
				}
				else
				{
					answerBad = false;
				}
			} while(answerBad);
 
			// Switch statement to enter user input
			switch(userInput)
			{
				// Subtract one from steps and subtract one from time,
				// and runs an encounter
				case 1: 
					currentPlayer.steps--;
					currentPlayer.time--;
					runEncounter(currentPlayer);
					break;
				// Add random number between 0-5 to intelligence, but sutbract
				// 2 fro time
				case 2: 
					currentPlayer.intelligence += rand() % 5;
					currentPlayer.time -= 2;
					break;
				// Adds a random amount of money between 0-5, but subtract 2
				// from time
				case 3:
					currentPlayer.money += rand() % 5;
					currentPlayer.time -= 2;
					break;
				// Print attributes of current player
				case 4:
					cout << "\n\n\tYou have:" << endl << endl
						 << "intelligence: " << currentPlayer.intelligence
						 << endl 
						 << "time: " << currentPlayer.time << endl
						 << "money: " << currentPlayer.money << endl;
				 // Quits game
				case 5:
					continueGame = false;
					break;
 
			}
 
			// Ends game if score is = 0
			if (currentPlayer.calculateScore() <= 0 || currentPlayer.steps == 0)
			{
				continueGame = false;
				// IF STATEMENT TO ADD HIGH SCORE IF ELIGIBLE
				if (checkIfHighScore(currentPlayer.score))
				{
					recordHighScore(currentPlayer.score,
									readFile1(highScoresFileInt));
 
				}
				// Print win message if steps is = 0, otherwise the player loses
				if (currentPlayer.steps == 0)
				{
					cout << "You have won!" << endl;
				}
				else
				{
					cout << "You lost." << endl;
				}
			}
		} while (continueGame);
	}
};
 
class HighScore
{
public:
	vector<int> readFile(string fileName);
	vector<string> readFile2(string fileName);
	// Variables
 
 
	// Constructor
	HighScore(void);
 
	// Functions
	// Read high scores file and print out high scores
	void runHighScore()
	{
		vector<string> highScores = readFile2(highScoresFileStr);
		cout << "The top 10 High Scores are:" << endl << endl;
		for (int i = 0; i < highScores.size(); i++)
		{
			cout << highScores[i] << endl;
		}
		cout << "-no more scores to show" << endl;
	}
 
	// Loop through high scores file and return true if user's score is equal
	// to or greater than the high scores, otherwise return false
	bool checkIfHighScore(int userScore)
	{
		vector<int> highScores = readFile(highScoresFileInt);
		for (int i = 0; i < highScores.size(); i++)
		{
			if (userScore >= highScores[i])
			{
				return true;
			}
		}
		return false;
	}
 
	// Records
	void recordHighScore(int scoreIn, vector<int> scoresIn)
	{
		for (int i = 0; i < scoresIn.size(); i++)
		{
			if (scoresIn[i] <= scoreIn)
			{
				for (int j = scoresIn.size() - 1; j == i; j--)
				{
					scoresIn[j - 1] = scoresIn[j];
				}
				scoresIn[i] = scoreIn;
			}
		}
		// WRITE HIGH SCORES TO FILE
	}
};
 
class File
{
public:
	// Constructor
	File(void);
 
	// Functions
	// Takes in string for file name and will open that file and create a 
	// vector of ints. Then it will return that vector
	vector<int> readFile(string fileName)
	{
		ifstream inFile(fileName);
		vector<int> inputVec(10);
		int i = 0;
		while (!inFile.eof())
		{
			inFile >> inputVec[i];
			i++;
		}
		inFile.close();
		return inputVec;
	}
 
	void writeFile1(string fileName, vector<int> outputVec)
	{
		ofstream outFile(fileName);
		for (int i = 0; i < outputVec.size(); i++)
		{
			outFile << outputVec[i] << endl;
		}
		outFile.close();
	}
};
 
 
void runMainMenu(Player& currentPlayer);
int main()
{
	Player currentPlayer;
	//Menu menu;
	menu.runMainMenu(currentPlayer);
	cout << "hi" << endl;
	return 0;
}
/*
 * Justin Sawyer
 * jts0047
 * Project1.cpp
 *
 * To compile I just ran "g++ -o project1 project1.cpp" in Terminal on my Linux machine.
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


// Global variables
string highScoresFileStr = "high_scores_string.txt"; // name of file for string
string highScoresFileInt = "high_scores_int.txt"; // name of file for ints

class File
{
public:
	//Constructor
	File() {}

	// Functions
	// Takes in string for file name and will open that file and create a 
	// vector of ints. Then it will return that vector
	vector<int> readFile(string fileName)
	{
		ifstream inFile(fileName);
		vector<int> inputVec;
		int i = 0;
		while (inFile >> i)
		{
			inputVec.push_back(i);
		}
		if (inputVec.size() == 0)
		{
			inputVec.push_back(0);
		}
		inFile.close();
		return inputVec;
	}

	void writeFile(string fileName, vector<int> outputVec)
	{
		ofstream outFile(fileName);
		for (int i = 0; i < outputVec.size(); i++)
		{
			outFile << outputVec[i] << endl;
		}
		outFile.close();
	}
 
};

class HighScore
{
public:
	// Variables
	File file;
 
	// Constructor
 	HighScore() {}

	// Functions
	// Read high scores file and print out high scores
	void runHighScore()
	{
		vector<int> highScores = file.readFile(highScoresFileInt);
		cout << "The top 10 High Scores are:" << endl;
		for (int i = highScores.size() - 1; i > 0; i--)
		{
			cout << highScores[i] << endl;
		}
		cout << "-no more scores to show" << endl << endl;
	}
 
	// Loop through high scores file and return true if user's score is equal
	// to or greater than the high scores, otherwise return false
	bool checkIfHighScore(int userScore)
	{
		vector<int> highScores = file.readFile(highScoresFileInt);
		for (int i = 0; i < highScores.size(); i++)
		{
			if (userScore >= highScores[i])
			{
				return true;
			}
		}
		return false;
	}
 
	// Records high score to file
	void recordHighScore(int scoreIn)
	{
		vector<int> scoresIn = file.readFile(highScoresFileInt);
		if (scoresIn.size() < 11)
		{
			scoresIn.push_back(scoreIn);
		}
		else
		{
			scoreIn = scoresIn[scoresIn.size()-1];
		}
		sort(scoresIn.begin(), scoresIn.end());

		// Writes high scores to file
		file.writeFile(highScoresFileInt, scoresIn);
	}
};

class Player
{
public:
	// Variables
	string userName;
	int intelligence, time, money, score, steps;

	// Constructor
	Player() {}

	// Functions
	int calculateScore()
	{
		score = intelligence * time * money;
		return score;
	}
};

class Menu
{
public:
	// Constructor
	Menu() {}

	// Functions
	// Will print main menu options
	void runMainMenu()
	{
		cout << "1) Start a New Game of Shelby Center and Dragons!" << endl
			 << "2) View top 10 High Scores" << endl
			 << "3) Quit" << endl;
	}

	void runGameMenu()
	{
		cout << "\t1) Move forward (takes time, could be risky...)" << endl
			 << "\t2) Read technical papers (boost intelligence, takes time)" << endl
			 << "\t3) Search for loose change (boost money, takes time)" << endl
			 << "\t4) View character" << endl
			 << "\t5) Quit the game" << endl;
	}

};

class Encounter
{
public:
	// Constructor
	Encounter() {}

	// Struct for puzzle objects
	struct Puzzle
	{

		string question, answer1, answer2, answer3, answer4;
		int correctAnswer;
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
	};

	// Functions
	void runEncounter(Player &currentPlayer)
	{
		int randEncounter = rand() % 100 + 1;
		// 25% chance nothing happens
		if (randEncounter < 25)
		{
			// Nothing happens
			cout << "No Encounter" << endl << endl; 
		}
		if (randEncounter >= 25 && randEncounter < 50)
		{
			int userInput;
			Puzzle puzzle = getPuzzles(createPuzzles());
			cout << "PUZZLE: " << puzzle.question
				 << "\n\t1) " << puzzle.answer1
				 << "\n\t2) " << puzzle.answer2
				 << "\n\t3) " << puzzle.answer3
				 << "\n\t4) " << puzzle.answer4
				 << "\n\nChoose Wisely: ";
 			cin >> userInput;
 			if (checkCorrectAnswer(puzzle, userInput))
 			{
 				cout << "Nice, you got it! You gain 5 time" << endl << endl;
 				currentPlayer.time += 5;
 			}
 			else
 			{
 				cout << "Aww, you got it wrong. You lose 2 time" << endl << endl;
 				currentPlayer.time -= 2;
 			}
		}
		// 10% chance to encounter a professor. Lose 0-2 time, but gain 
		// 0-4 intelligence
		if (randEncounter >= 50 && randEncounter < 60)
		{
			int loss = rand() % 3, gain = rand() % 3;
			currentPlayer.time -= loss;
			currentPlayer.intelligence += gain;\
			cout << "You just encountered a professor. You lost " << loss
				 << " time, but gained " << gain << " intelligence\n\n";
		}
		// 10% chance to encounter a grad student. Lose 0-2 time
		if (randEncounter >= 60 && randEncounter < 70)
		{
			int loss = rand() % 3;
			currentPlayer.time -= loss;
			cout << "You just encountered a grad student. You lose " << loss
				 << " time." << endl << endl;
 
		}
		// 15% chance to encounter grunt work. Lose 0-2 time and intelligence
		if (randEncounter >= 70 && randEncounter < 85)
		{
			int loss = rand() % 3, loss2 = rand() % 3;
			currentPlayer.time -= loss;
			currentPlayer.intelligence -= loss2;
			cout << "You just encountered grunt work. You lose " << loss
				 << " time and " << loss2 << " intelligence" << endl << endl;
		}
		// 15% chance to encounter grade papers. Lose 0-2 time, but gain 
		// 0-4 money
		if (randEncounter >= 85 && randEncounter <= 100)
		{
			int loss = rand() % 3, gain = rand() % 5;
			currentPlayer.time -= loss;
			currentPlayer.money += gain;
			cout << "You just encountered grunt work. You lose " << loss
				 << " time, but gain " << gain << " intelligence" << endl << endl;
		}
	}
	// Initializes some Puzzle objects and sotres them in a vector, then
	// return the vector
	vector<Puzzle> createPuzzles()
	{
		string question1, question2, question3, question4, answer11, answer12,
			answer13, answer14, answer21, answer22, answer23, answer24, 
			answer31, answer32, answer33, answer34, answer41, answer42,
			answer43, answer44;

		question1 = "If a bat and a ball cost $1.10 and the bat is $1.00 more "
					"than the ball, how much does the bat cost?";
		answer11 = "$1.00";
		answer12 = "$.95";
		answer13 = "$.05";
		answer14 = "$1.05";
		Puzzle puzzle1 = Puzzle(question1, answer11, answer12, answer13, 
								answer14, 4);

		question2 = "What is black, white, and read all over";
		answer21 = "A newspaper";
		answer22 = "A penguin with a rash";
		answer23 = "A referee butchering some meat";
		answer24 = "A panda after a meal";
		Puzzle puzzle2 = Puzzle(question2, answer21, answer22, answer23, 
								answer24, 1);

		question3 = "2 + 2 * 2 =";
		answer31 = "2";
		answer32 = "4";
		answer33 = "6";
		answer34 = "8";
		Puzzle puzzle3 = Puzzle(question3, answer31, answer32, answer33, 
								answer34, 3);

		question4 = "Mary's mom has four children Mark, Luke, and Anthony. "
					"What is the name of the fourth?";
		answer41 = "John";
		answer42 = "Mary";
		answer43 = "Mark";
		answer44 = "Bob";
		Puzzle puzzle4 = Puzzle(question4, answer41, answer42, answer43, 
								answer44, 2);
		vector<Puzzle> puzzleVec = {puzzle1, puzzle2, puzzle3, puzzle4};
		return puzzleVec;
	}
 
	// Chooses a random puzzle from the vector in parameter and returns it
	Puzzle getPuzzles(vector<Puzzle> puzzleVecIn)
	{
		int randPuzzle = rand() % puzzleVecIn.size() + 1;
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

class System
{
public:
	// Variables
	Player currentPlayer;
	Menu menu;
	Encounter encounter;
	HighScore highScore;

	// Constructor
	System () {}

	// Functions
	void runSystem()
	{

		int userInput, userInput2;
		string userName;

		// Prints welcome message and shanges name of user
		cout << "What's your name? ";
		cin >> userName;
		cout << "\n\n================================================================"
			 << "\n|" << setw(41 - userName.size()) << "Welcome " + userName 
			 << setw(28) <<" |"
			 << "\n================================================================\n\n";
		currentPlayer.userName = userName;

		// Do-while loop to keep running main menu
		bool continueGame3 = true;
		do
		{	
			// Runs while loop for user input until they typed an answer in bounds
			bool continueGame = true;
			do
			{
				menu.runMainMenu();
				cout << "\n\tPlease choose an option: ";
				cin >> userInput;
				cout << endl << endl;

				if (userInput < 1 || userInput > 3)
				{
					cout << "\nPlease re-type an answer that is between 1 - 3.\n\n";
				}
				else
				{
					continueGame = false;
				}
			} while (continueGame);

			// Swtich statement to choose what the user inputs
			bool continueGame2 = true;
			switch(userInput)
			{
				// Start a game
				case 1:
					currentPlayer.steps = 20;
					currentPlayer.intelligence = rand() % 17 + 8;
					currentPlayer.time = rand() % 5 + 30;
					currentPlayer.money = rand() % 17 + 8;
					// While loop to keep running game until score is =< 0
					do
					{
						// While loop to continue asking user actions until answer
						// is in bounds
						srand(time(0));
						bool badAnswer = true;
						do 
						{
							cout << "You are " << currentPlayer.steps << " from the "
								 << "goal. Time left: " << currentPlayer.time 
								 << endl << endl;
							menu.runGameMenu();
							cout << "\n\n\tPlease choose an action: ";
							cin >> userInput2;
							cout << endl;

							if (userInput2 < 1 || userInput2 > 5)
							{
								cout << "\nPlease re-type an answer that is between "
									 << "1 - 5.\n\n";
							}
							else 
							{
								badAnswer = false;
							}
						}  while (badAnswer);

						switch (userInput2)
						{
							// Move Forward. Decrement steps and time. Run encounter
							case 1:
								currentPlayer.steps--;
								currentPlayer.time--;
								encounter.runEncounter(currentPlayer);
								break;
							// Read technical papers. boost intelligence
							// Subtract 2 from time
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
									 << "money: " << currentPlayer.money << endl << endl;
									 break;
							// Will quit game
							case 5:
								continueGame2 = false;
								break;

						}

						// If user score is <= 0 then game ends
						if (currentPlayer.calculateScore() <= 0)
						{
							cout << "You hit 0 points. You lost." << endl << endl;
							continueGame2 = false;
						}
						else if (currentPlayer.steps == 0)
						{
							cout << "Congratulations, you won with a "
								 << "score of " << currentPlayer.calculateScore()
								 << "!" << endl << endl;
							continueGame2 = false;
						}

					} while(continueGame2); 


					// If steps = 0, then it will check if eligible and records high score.
					if (currentPlayer.steps == 0)
					{
						if (highScore.checkIfHighScore(currentPlayer.calculateScore()))
						{
							highScore.recordHighScore(currentPlayer.calculateScore());
							cout << "Congratulations, you made it on the high "
								 << "score list!" << endl << endl;
						}
					}
					break;
				// Print to user the top, up to, ten high scores
				case 2:
					highScore.runHighScore();
					break;
				// Ends game
				case 3:
					continueGame3 = false;
					cout << "You have chosen to quit game" << endl << endl;
					break;

			}
		} while (continueGame3);
	}
};

int main()
{
	srand(time(0));
	System system;
	system.runSystem();

	return 0;
}

/**** Test Results
	* Test 1: First high score was written correctly.
	* Test cases passed
	*
	* Test 2: Ninth high score was written correctly.
	* Test cases passed
	*
	* Test 3: Tenth high score was written correctly.
	* Test cases passed
	*
	* Test 4: Check out of bounds for user input in main menu.
	* Test cases passed
	*
	* Test 5: Check out of bounds for user input in game menu.
	* Test cases passed
	*
	* Test 6: readFileTest() Tests readFile for proper functionality.
	* Test cases passed
	*
	* Test 7: writeFile() Tests writeFile for proper functionality.
	* Test cases passed
	*
	* Test 8: checkIfHighScoreTest() Tests checkIfHighScore for proper functionality.
	* Test cases passed
	*
	* Test 9: createPuzzlesTest() Test creatPuzzles() for proper functionality.
	* Test cases passed
	*
	* Test 10: calculateScoreTest() Tests calculateScire for proper functionality
	* Test cases passed
	*
	*****/
/******************************************************************************
* Programmer: Chad Thornton
*
* Assigned Project Number: 6A
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     02/08/2016  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  The program accepts double values between 0 and 10 from the user.
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   The program displays the judge's scores to the console, and also displays the
*			overall score after taking away the highest and lowest score.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
void getJudgeData(double &);
double calcScore(double[]);
double findLowest(double[]);
double findHighest(double[]);
void toLower(string&);
char toLower(char);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** The program will ask the user for each judge's score, and will wait for 
* ** the user to input a double value between 0 and 10. After the program has
* ** accepted scores for the 5 judges it will then take away the highest and 
* ** lowest score and then take the average of the three remaining scores.
* ** The average score will then be displayed to the console. Afterwards the
* ** program will then ask the user if they want to calculate scores for 
* ** another performer.
*
*
* Preconditions
* -------------
* User will input double values.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations
	string goAgain;
	do
	{
		double judgeNum = 1,
			score[5],
			totalScore;

		for (int i = 0; i < 5; i++)
		{
			cout << "Judge #" << judgeNum << "'s score for the performer is: ";
			getJudgeData(score[i]);
			judgeNum++;
		}

		totalScore = calcScore(score);

		cout << "\nThe performers overall score is: " << setprecision(2) << totalScore << endl;
		cout << "\nWould you like to calculate another performers overall score? (Yes/No)" << endl;
		cin >> goAgain;
		toLower(goAgain);
		while ((goAgain != "yes") && (goAgain!="no"))
		{
			cout << "Sorry that was not a valid input. Please answer yes or no.\n";
			cout << "Would you like to calculate another performers overall score? (Yes/No)";
			cin >> goAgain;
			toLower(goAgain);
		}
	} while (goAgain == "yes");

	cout << "Thank you for using our program.\nHave a nice day!" << endl;

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()


void getJudgeData(double& score)
{
	cin >> score;
	while ((score<0) || (score>10))
	{
		cout << "Score must be a number between 0 and 10\nPlease enter a valid score.";
		cin >> score;
	}
}

double calcScore(double score[])
{
	double MAX_JUDGES = 3,
		sum = 0,
		lowestScore,
		highestScore;
	for (int i = 0; i < 5; i++)
	{
		sum += score[i];
	}

	lowestScore = findLowest(score);
	highestScore = findHighest(score);
	sum = (sum - (lowestScore + highestScore)) / MAX_JUDGES;

	return sum;
}
double findLowest(double score[])
{
	double lowest = score[0];
	for (int i = 0; i < 5; i++)
	{
		if (score[i] < lowest)
			lowest = score[i];
	}
	return lowest;
}
double findHighest(double score[])
{
	double highest = score[0];
	for (int i = 0; i < 5; i++)
	{
		if (score[i] > highest)
			highest = score[i];
	}
	return highest;
}

void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}
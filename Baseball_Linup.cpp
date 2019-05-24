#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

const int NUMBEROFPLAYERS = 12;
const int NUMBEROFINNINGS = 5;
const int NUMBEROFPOSITIONS = 12;
int const ROWS = 12;
int const COLS = 5;

string NAMESOFPLAYERS[NUMBEROFPLAYERS];
int PLAYERAVERAGESCORES[NUMBEROFPLAYERS];

void obtainPlayerNames(string namesOfPlayers[NUMBEROFPLAYERS]);
void obtainPlayerAverageScore(int playerAverageScores[NUMBEROFPLAYERS]);
void arrangePlayersByDescendingAverageScore(int playerAverageScores[NUMBEROFPLAYERS], string namesOfPlayers[NUMBEROFPLAYERS]);
void columnLabelHeaders();
void displayArray(string playerPositionArray[ROWS][COLS]);

int main() {
	//declarations
	string playerPositionArray[ROWS][COLS] = { {"1B  ","RF  ","OUT2","2B  ","SS  "},
											   {"2B  ","LCF ","SS  ","RCF ","OUT1"},
											   {"SS  ","OUT1","2B  ","LCF ","P   "},
											   {"3B  ","LF  ","P   ","RF  ","C   "},
											   {"P   ","RCF ","3B  ","OUT1","2B  "},
											   {"C   ","OUT2","RF  ","1B  ","LCF "},
											   {"LF  ","3B  ","RCF ","P   ","1B  "},
											   {"LCF ","2B  ","1B  ","OUT2","LF  "},
											   {"RF  ","1B  ","OUT1","3B  ","RCF "},
											   {"RCF ","P   ","LF  ","C   ","OUT2"},
											   {"OUT1","SS  ","C   ","LF  ","3B  "},
											   {"OUT2","C   ","LCF ","SS  ","RF  "}, };

	//get user input
	cout << "Enter 12 player names: " << endl;
	// Populate NAMESOFPLAYERS array with names
	obtainPlayerNames(NAMESOFPLAYERS); 
	cout << endl;

	cout << "Enter the averages for each player " << endl;
	cout << "---------------------------------- " << endl;
	// Populate PLAYERAVERAGESCORES array with averages
	obtainPlayerAverageScore(PLAYERAVERAGESCORES); 
	cout << endl;

	cout << "Game lineup and field positions: " << endl;
	cout << "-------------------------------- " << endl;

	//Rearranges players by descending averages (high to low)
	arrangePlayersByDescendingAverageScore(PLAYERAVERAGESCORES, NAMESOFPLAYERS); 
	//Generates header for lineup
	columnLabelHeaders();
	cout << endl;
	//Displays names in descending order and assigns position in every inning for each player
	displayArray(playerPositionArray);

	system("pause");
	return 0;
}

void obtainPlayerNames(string namesOfPlayers[NUMBEROFPLAYERS]) {
	for (int counter = 0; counter < NUMBEROFPLAYERS; counter += 1)
	{
		cout << "What is player " << counter + 1 << "'s name: ";
		cin >> namesOfPlayers[counter];

	}
}

void obtainPlayerAverageScore(int playerAverageScores[NUMBEROFPLAYERS]) {
	for (int counter = 0; counter < NUMBEROFPLAYERS; counter += 1)
	{
		cout << "What is " << NAMESOFPLAYERS[counter] << "'s average: ";
		cin >> playerAverageScores[counter];
	}
}

void arrangePlayersByDescendingAverageScore(int playerAverageScores[NUMBEROFPLAYERS], string namesOfPlayers[NUMBEROFPLAYERS]) {
	int tempArrayAverageIndex;
	string tempArrayNameIndex;
	for (int i = 0; i < NUMBEROFPLAYERS; i++) {
		for (int j = i + 1; j < NUMBEROFPLAYERS; j++) {
			if (playerAverageScores[i] < playerAverageScores[j]) {
				tempArrayAverageIndex = playerAverageScores[i];
				tempArrayNameIndex = namesOfPlayers[i];
				playerAverageScores[i] = playerAverageScores[j];
				namesOfPlayers[i] = namesOfPlayers[j];
				playerAverageScores[j] = tempArrayAverageIndex;
				namesOfPlayers[j] = tempArrayNameIndex;
			}
		}
	}
}

void columnLabelHeaders() {
	const int NUMOFCOLUMNS = 6;
	string column[NUMOFCOLUMNS] = { "Name", "Inning 1", "Inning 2", "Inning 3", "Inning 4", "Inning 5" };
	string columnArrayIndex;
	int numOfSpacesBetweenText = 13;

	for (int i = 0; i < NUMOFCOLUMNS; i += 1)
	{
		columnArrayIndex = column[i];
		cout << column[i];
		// Set the spaces between each column header
		for (int i = 0; i < NUMOFCOLUMNS; i += 1)
		{
			cout << " ";
		}
	}
}

void displayArray(string playerPositionArray[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++)
	{
		cout << NAMESOFPLAYERS[i]; 
		/* Subtract the lenght of each name from 10 so that the loop will
		cout the remaining spaces - creating a uniform look*/
		for (int k = 0; k < 10 - NAMESOFPLAYERS[i].length(); k++) {
			cout << " ";
		}
		// Display the 2D array
		for (int j = 0; j < COLS; j++)
		{
			cout << playerPositionArray[i][j] << "          ";
		}
		cout << endl;
	}
}
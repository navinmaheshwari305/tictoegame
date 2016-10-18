//============================================================================
// Name        : games.cpp
// Author      : Navin
// Version     :
// Copyright   : MY Rules
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <ctype.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string whoWon();
int compInput();
void printResults();
void draw();
void togglePlayer();
void takeInput();

string board[3][3] = {"1","2","3","4","5","6","7","8","9"};
string player = "X" ;
int input= -1;
string uInput = "";
string winner= "*";
int level =1;



void togglePlayer()
{
	if(player == "X")
		player = "O";
	else
		player = "X";
}


void draw()
{
	system("cls");
	cout << endl;
	cout << "+++++++++++" << endl;
	cout << "+         +" <<endl;
	for(int i=0;i<3;i++)
	{
		cout << "+  ";
		for(int j=0;j<3;j++)
		{
			cout <<  board[i][j] << " " ;
		}
		cout << " +"<< endl;
	}
	cout << "+         +" <<endl;
	cout << "+++++++++++" << endl;
}

void takeInput()
{

	while(true){
		if(player == "X")
		{
			cout << "Player " << player << " turn : ";
			cin >> uInput;
			while(!isdigit(uInput[0]) || atoi(uInput.c_str()) > 9 || atoi(uInput.c_str()) < 1)
			{
				cout << "Wrong Input. Try Again..." << endl;
				cout << "Player " << player << " turn : ";
				cin >> uInput;
			}
			input = atoi(uInput.c_str());
		}
		else
		{
			input = compInput();
		}
		if(board[(input-1)/3][((input%3)+2)%3] == "X" || board[(input-1)/3][((input%3)+2)%3] == "O")
		{
			if(player == "X")
				cout << "Position already Occupied.. Please try again." << endl;
		}else
		{
			if(player != "X")
				cout <<"my turn : " << input << endl;
			board[(input-1)/3][((input%3)+2)%3] = player;
			break;
		}
	}
}

int compInput()
{
	return  (rand() % 9)+1; // no intelligence


}

string whoWon()
{
	string winner;
	for(int i=0;i<3;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}

		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if(board[0][0] == board[1][1] && board[2][2] == board[1][1])
	{
		return board[1][1];
	}
	if(board[0][2] == board[1][1] && board[2][0] == board[1][1])
	{
		return board[1][1];
	}
	return "*";
}

void printResults()
{
	draw();
	if(winner == "*")
	{
		cout << "*************************************************" <<endl;
		cout << "*                                               *" << endl;
		cout << "*                  Game Draw                    *" << endl;
		cout << "*                                               *" << endl;
		cout << "*************************************************" <<endl;
	}
	else if(winner == "X" || winner == "O" )
	{
		cout << "*************************************************" <<endl;
		cout << "*                                               *" << endl;
		cout << "*                  Winner is " << winner <<"                  *" << endl;
		cout << "*                                               *" << endl;
		cout << "*************************************************" <<endl;
	}

}

int main(void) {
	srand(time(0));
	int n = 9;
	while(n-- && winner == "*")
	{
		draw();
		takeInput();
		winner = whoWon();
		togglePlayer();
	}
	printResults();
}

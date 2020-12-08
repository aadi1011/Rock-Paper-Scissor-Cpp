#include<iostream>
#include <string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class RPS
{
public:
	string p1, p2;
	char startchoice{}, p1choice{}, p2choice{}, repeatchoice{};
	int round{};

	void username();
	void userchoice();
	void rounds();
	void game();
	void p1error();
	void p2error();
	void repeat();
	void exitgame();
};

void RPS::username()
{
	cout << "Enter your name player 1: " << endl;
	cin >> p1;
	cout << endl << "Enter your name player 2: " << endl;
	cin >> p2;
	system("cls");
	userchoice();
}

void RPS::userchoice()
{
	cout << "Welcome, " << p1 << " and " << p2 << ". \nAre you ready to play Rock, Paper, Scissors? (y/n)" << endl;
	cin >> startchoice;
	if (startchoice == 'y' || startchoice == 'Y')
	{
		system("cls");
		rounds();
	}
	else if (startchoice == 'n' || startchoice == 'N')
	{
		system("cls");
		exitgame();
	}
	else
	{
		system("cls");
		cout << "Invalid options entered. Please try again using yes (y) or no (n)" << endl << endl;
		userchoice();
	}
}

void RPS::rounds()
{
	cout << "Enter the number of rounds you want to play (1-20): " << endl;
	cin >> round;
	if (round < 1 || round>20)
	{
		system("cls");
		cout << "Number outside limits. Please enter between 1-20" << endl;
		rounds();
	}
	else
	{
		system("cls");
		game();
	}
}

void RPS::game()
{
	for (int i = 1; i <= round; i++)
	{
		cout << "Round " << i << endl << endl;

		cout << p1 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
		cin >> p1choice;

		if (p1choice == 'r' || p1choice == 'R')
		{
			cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
			cin >> p2choice;

			if (p2choice == 'r' || p2choice == 'R')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> " << p2 << " is the winner" << endl << endl << endl << endl;
			}
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
			}
			else
			{
				p2error();
			}
		}

		else if (p1choice == 'p' || p1choice == 'P')
		{
			cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
			cin >> p2choice;

			if (p2choice == 'r' || p2choice == 'R')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
			}
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> " << p2 << " is the winner" << endl << endl << endl << endl;
			}
			else
			{
				p2error();
			}
		}

		else if (p1choice == 's' || p1choice == 'S')
		{
			cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
			cin >> p2choice;

			if (p2choice == 'r' || p2choice == 'R')
			{
				cout << "--> " << p2 << " is the winner" << endl << endl << endl << endl;
			}
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
			}
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else
			{
				p2error();
			}
		}
		else
		{
			p1error();
		}
	}
	system("pause");
	repeat();
}

void RPS::p1error()
{
	system("cls");
	cout << p1 << ", you have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)" << endl << endl << endl << endl;
	game();
}

void RPS::p2error()
{
	system("cls");
	cout << p2 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)" << endl << endl << endl << endl;
	game();
}

void RPS::repeat()
{
	system("cls");
	cout << endl << "Would you like to play again? (y/n)";
	cin >> repeatchoice;
	if (repeatchoice == 'Y' || repeatchoice == 'y')
	{
		system("cls");
		rounds();
	}
	else if (repeatchoice == 'N' || repeatchoice == 'n')
	{
		system("cls");
		exitgame();
	}
	else
	{
		cout << "Invalid option selected. Please select with either Y or N" << endl;
		repeat();
	}
}

void RPS::exitgame()
{
	system("cls");
	cout << endl << endl << "Thank you for playing, " << p1 << " and " << p2 << " hope you had a great time" << endl << endl;
	system("pause");
	exit(0);
}

int main()
{
	RPS gameclass;
	gameclass.username();
	return 0;
}
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
void username(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void playerchoice(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void game(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void p1error(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void p2error(char play,string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void repeat(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice);
void exitgame(string p1, string p2);

void username(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << "Enter your name, Player one" << endl;
	cin >> p1;
	cout << endl << "Enter your name, Player two" << endl;
	cin >> p2;
	playerchoice(play, p1, p2, p1choice, p2choice, repeatchoice);
}

void playerchoice(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << endl << endl << "Welcome " << p1 << " and " << p2 << endl;
	cout << "Are you ready to play Rock Papers Scissors? (y/n)";
	cin >> play;

	if (play == 'y' || play == 'Y')
	{
		game(play, p1, p2, p1choice, p2choice, repeatchoice);
	}
	else if (play == 'n' || play == 'N')
	{
		exitgame(p1, p2);
	}
	else
	{
		cout << endl << "Invalid option, Please try again with (y/n)" << endl;
		playerchoice(play, p1, p2, p1choice, p2choice, repeatchoice);
	}
}

void game(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << endl << "------------------------------------------------------------------------" << endl << endl;
	cout << "The game shall start now" << endl << endl;

	cout << p1 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
	cin >> p1choice;
	cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
	cin >> p2choice;

	if (p1choice == 'r' || p1choice == 'R')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << "It's a draw" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << p2 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << p1 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else
		{
			 p2error(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
	}
	
	else if (p1choice == 'p' || p1choice == 'P')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << p1 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << "It's a draw" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << p2 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else
		{
			p2error(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
	}

	else if (p1choice == 's' || p1choice == 'S')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << p2 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << p1 << " is the winner" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << "It's a draw" << endl << endl;
			repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
		else
		{
			p2error(play, p1, p2, p1choice, p2choice, repeatchoice);
		}
	}
	else
	{
		p1error(play, p1, p2, p1choice, p2choice, repeatchoice);
	}
}

void p1error(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << endl << endl << p1 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)";
	game(play, p1, p2, p1choice, p2choice, repeatchoice);
}

void p2error(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << endl << endl << p2 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)";
	game(play, p1, p2, p1choice, p2choice, repeatchoice);
}

void repeat(char play, string p1, string p2, char p1choice, char p2choice, char repeatchoice)
{
	cout << endl << "Would you like to play again? (y/n)";
	cin >> repeatchoice;
	if (repeatchoice == 'Y' || repeatchoice == 'y')
	{
		cout << "\033[2J\033[1;1H";
		game(play, p1, p2, p1choice, p2choice, repeatchoice);
	}
	else if (repeatchoice == 'N' || repeatchoice == 'n')
	{
		cout << "\033[2J\033[1;1H";
		exitgame(p1, p2);
	}
	else
	{
		cout << "Wrong choice selected. Please select with either Y or N" << endl;
		repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
	}
}

int main()
{
	string p1, p2;
	char play{}, p1choice{}, p2choice{}, repeatchoice{};
	username (play, p1, p2, p1choice, p2choice, repeatchoice);
	playerchoice(play, p1, p2, p1choice, p2choice, repeatchoice);
	game(play, p1, p2, p1choice, p2choice, repeatchoice);
	p1error(play, p1, p2, p1choice, p2choice, repeatchoice);
	p2error(play, p1, p2, p1choice, p2choice, repeatchoice);
	repeat(play, p1, p2, p1choice, p2choice, repeatchoice);
	exitgame(p1, p2);
	return 0;
}

void exitgame(string p1, string p2)
{
	cout << endl << endl << "Thank you for playing, " << p1 << " and " << p2 << " hope you had a great time" << endl << endl;
	system("pause");
	exit(0);
}

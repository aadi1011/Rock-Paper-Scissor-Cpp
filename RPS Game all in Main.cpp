#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

void main()
{
	string p1, p2;
	char play, p1choice, p2choice, repeatchoice;
	cout << "Enter your name, Player one" << endl;
	cin >> p1;
	cout << endl << "Enter your name, Player two" << endl;
	cin >> p2;
	
playchoice:
	cout << endl << endl << "Welcome " << p1 << " and " << p2 << endl;
	cout << "Are you ready to play Rock Papers Scissors? (y/n)";
	cin >> play;
	
	if (play == 'y' || play == 'Y')
	{
		goto Game;										
	}
	else if (play == 'n' || play == 'N')
	{
		goto Exit;			
	}
	else
	{
		cout << endl << "Invalid option, Please try again with (y/n)" << endl;
		goto playchoice;
	}


Game:
	cout << endl << "------------------------------------------------------------------------" << endl << endl;
	cout << "The game shall start now" << endl << endl;

	cout << p1 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
	cin >> p1choice;
	cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
	cin >> p2choice;


Player1Choice:
	if (p1choice == 'r' || p1choice== 'R')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << "It's a draw" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << p2 << " is the winner" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << p1 << " is the winner" << endl << endl;
			goto Repeat;
		}
		else
		{
			goto P2Error;
		}
	}

	else if (p1choice == 'p' || p1choice == 'P')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << p1 << " is the winner" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << "It's a draw" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << p2 << " is the winner" << endl << endl;
			goto Repeat;
		}	
		else
		{
			goto P2Error;
		}
	}

	else if (p1choice == 's' || p1choice == 'S')
	{
		if (p2choice == 'r' || p2choice == 'R')
		{
			cout << p2 << " is the winner" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 'p' || p2choice == 'P')
		{
			cout << p1 << " is the winner" << endl << endl;
			goto Repeat;
		}
		else if (p2choice == 's' || p2choice == 'S')
		{
			cout << "It's a draw" << endl << endl;
			goto Repeat;
		}
		else
		{
			goto P2Error;
		}
	}
	else
	{
		goto P1Error;
	}	


P1Error:
	cout << endl << endl << p1 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)";
	goto Game;


P2Error:
	cout << endl << endl << p2 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)";
	goto Game;


Repeat:
	cout << endl << "Would you like to play again? (y/n)";
	cin >> repeatchoice;
	if (repeatchoice=='Y'|| repeatchoice=='y')
	{
		cout << "\033[2J\033[1;1H";
		goto Game;
	}
	else if (repeatchoice=='N'|| repeatchoice=='n')
	{
		cout << "\033[2J\033[1;1H";
		goto Exit;
	}
	else
	{
		cout << "Wrong choice selected. Please select with either Y or N" << endl;
		goto Repeat;
	}


Exit:
	cout << endl << endl << "Thank you for playing, " << p1 << " and " << p2 << " hope you had a great time" << endl << endl;
}

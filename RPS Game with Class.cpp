// C++ Code for Rock-Paper-Scissors Game
// Code by Aadith Sukumar (https://www.github.com/aadi1011)
// Available in repository (https://github.com/aadi1011/Rock-Paper-Scissor-Cpp)

#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main();
// Main Class of the program
class RPS
{
//Public functions and variables
//Public functions can be accessed by any function in the program
public:
	string p1, p2;
	//Char declarations to take choices
	char startchoice{}, p1choice{}, p2choice{}, repeatchoice{};
	int round{}, introchoice{};
	// Primary Functions of RPS Game 
    // Function to start the game
	void username();
	void userchoice();
	void rounds();
	void game();//game function with the algorithms to run the primary driver of the game
	void p1error();
	void p2error();
	void repeat();
	void computer();
	void exitgame();//exit function to exit the game
};

//Username function
void RPS::username()
{
    //Taking input from the user for the names of the players
	cout << "Enter your name player 1: " << endl;
	cin >> p1;
	cout << endl << "Enter your name player 2: " << endl;
	cin >> p2;
	system("cls");
    //Calling the userchoice function
    //proceeding to the next function
	userchoice();
}

//Userchoice function
void RPS::userchoice()
{
	cout << "Welcome, " << p1 << " and " << p2 << ". \nAre you ready to play Rock, Paper, Scissors? (y/n)" << endl;
	cin >> startchoice;
    //first choice of the user 
    //if the user enters y, the game will start
    //if the user enters n, the game will exit
	if (startchoice == 'y' || startchoice == 'Y')
	{
		system("cls");
		rounds();//proceeding to the next function - rounds
	}
	else if (startchoice == 'n' || startchoice == 'N')
	{
		system("cls");
		exitgame();//proceeding to the function - exitgame
	}
	else
	{
		system("cls");
		cout << "Invalid options entered. Please try again using yes (y) or no (n)" << endl << endl;
		userchoice();//recursive function to call the userchoice function again
	}
    //if the user enters any other option, the program will ask the user to enter the option again
    //the program will keep asking the user to enter the option until the user enters y or n
    //keyboard interrupt of ctrl+c will also exit the program
    //the program will not accept any other option
}

//Rounds function
void RPS::rounds()
{
	cout << "Enter the number of rounds you want to play (1-20): " << endl;
	cin >> round;
    //limiting the number of rounds to 20
    //the game is not designed to play more than 20 rounds
    //if the user enters a number greater than 20, the program will ask the user to enter the number again
	if (round < 1 || round>20) //edit the second number of rounds to change the upper cap on the number of rounds
	{
		system("cls");
		cout << "Number outside limits. Please enter between 1-20" << endl;
		rounds();
	}
	else
	{
		system("cls");
		game();//proceeding to the next function - game
        //the game function will run the primary driver of the game
	}
}// Code by Aadith Sukumar (https://www.github.com/aadi1011)

//Game function
//do not edit this function unless you know what you are doing
//alterations to this function may cause the program to malfunction
void RPS::game()
{
    //for loop to run the game for the number of rounds entered by the user
	int p1tally=0, p2tally=0;
	for (int i = 1; i <= round; i++)
	{
		//round call
        cout << "Round " << i << endl << endl;

        //player 1 prompt
		cout << p1 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
		cin >> p1choice;
        
        //game logic will revolve around the choice of player 1
        //if user enters any of 'r', 'p', 's', 'R', 'P', 'S', the program will proceed to the next step
        //if the user enters any other option, the program will ask the user to enter the option again
		if (p1choice == 'r' || p1choice == 'R')
		{
            //player 2 prompt
			cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
			cin >> p2choice;

            //game logic will now revolve around the choice of player 2
            //if user enters any of 'r', 'p', 's', 'R', 'P', 'S', the program will proceed to the next step
			if (p2choice == 'r' || p2choice == 'R')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl; //Declaring a draw
			}// Code by Aadith Sukumar (https://www.github.com/aadi1011)
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> " << p2 << " is the winner" << endl << endl << endl << endl;//Declaring player 2 as the winner
				p2tally++;
			}
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;   //Declaring player 1 as the winner
				p1tally++;
			}
            //if the user enters any other option, the program will ask the user to enter the option again
            //the else for the player 2 choice is inside the if for player 1 choice
            //this is to be updated in such to ensure that the program will not ask the player 1 to enter the option again 
            //if the player 2 enters an invalid option
			else
			{
				p2error();//proceeding to the function - p2error
			}
            //if the user enters any other option, the program will ask the user to enter the option again
		}

        //second if for player 1 choice
        //if the user enters any of 'r', 'p', 's', 'R', 'P', 'S', the program will proceed to the next step
		else if (p1choice == 'p' || p1choice == 'P')
		{
            //player 2 prompt
			cout << p2 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
			cin >> p2choice;

            //game logic will now revolve around the choice of player 2
            //if user enters any of 'r', 'p', 's', 'R', 'P', 'S', the program will proceed to the next step
			if (p2choice == 'r' || p2choice == 'R')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
				p1tally++;
			}
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> " << p2 << " is the winner" << endl << endl << endl << endl;
				p2tally++;
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
				p2tally++;
			}
			else if (p2choice == 'p' || p2choice == 'P')
			{
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
				p1tally++;
			}// Code by Aadith Sukumar (https://www.github.com/aadi1011)
			else if (p2choice == 's' || p2choice == 'S')
			{
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else
			{
				p2error();
			}
		}
        
        //if the player 1 enters any other option, the program will ask the user to enter the option again
        //the else for the player 1 choice is outside the if for player 1 choice
        //this is ensures that the program will ask the player 1 to enter the option again
		else
		{
			p1error();
		}
	}
    //the game function will end here
	system("pause");
	system("cls");
	// score declaration based on the tally
	cout<<"Scores: \n"<<p1<<" : "<<p1tally<<"\n"<<p2<<" : "<<p2tally<<endl<<endl;
	if (p1tally > p2tally)
	{
		cout << p1 << " is the winner" << endl << endl << endl << endl;
	}
	else if (p1tally < p2tally)
	{
		cout << p2 << " is the winner" << endl << endl << endl << endl;
	}
	else
	{
		cout << "It's a draw" << endl << endl << endl << endl;
	}
	system("pause");

	repeat(); //proceeding to the function - repeat
    //the repeat function will ask the user if they want to play again
    //executes after all iterations of the for loop are completed
}

//p1error function
void RPS::p1error()
{
	system("cls");
	cout << p1 << ", you have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)" << endl << endl << endl << endl;
	game(); //returns to the game function
}// Code by Aadith Sukumar (https://www.github.com/aadi1011)

//p2error function
//this function is similar to the p1error function
//the only difference is that the prompt is for player 2
//to be updated to ensure that the program will not ask the player 1 to enter the option again
void RPS::p2error()
{
	system("cls");
	cout << p2 << " You have chosen invalid options, please select either Rock (r), Paper (p) or Scissor (s)" << endl << endl << endl << endl;
	game();//returns to the game function
}

//repeat function
void RPS::repeat()
{
	system("cls");
	cout << endl << "Would you like to play again? (y/n)";
	cin >> repeatchoice;
	if (repeatchoice == 'Y' || repeatchoice == 'y')
	{
		system("cls");
		main();
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

// player vs computer function
void RPS::computer()
{
	int p1tally=0, p2tally=0;
	system("cls");
	cout << "Please enter your name" << endl;
	cin >> p1;
	cout << "Please enter the number of rounds you would like to play" << endl;
	cin >> round;
	system("cls");
	for (int i = 0; i < round; i++)
	{
		cout << p1 << ", please choose your move Rock, Paper or Scissor (R, P, S)" << endl;
		cin >> p1choice;
		if (p1choice == 'r' || p1choice == 'R')
		{
			cout << "--> " << p1 << " has chosen Rock" << endl;
			p2choice = rand() % 3 + 1;
			if (p2choice == 1)
			{
				cout << "--> Computer has chosen Rock" << endl;
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else if (p2choice == 2)
			{
				cout << "--> Computer has chosen Paper" << endl;
				cout << "--> Computer is the winner" << endl << endl << endl << endl;
				p2tally++;
			}
			else if (p2choice == 3)
			{
				cout << "--> Computer has chosen Scissor" << endl;
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
				p1tally++;
			}
			else
			{
				p2error();
			}
		}
		else if (p1choice == 'p' || p1choice == 'P')
		{
			cout << "--> " << p1 << " has chosen Paper" << endl;
			p2choice = rand() % 3 + 1;
			if (p2choice == 1)
			{
				cout << "--> Computer has chosen Rock" << endl;
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
				p1tally++;
			}
			else if (p2choice == 2)
			{
				cout << "--> Computer has chosen Paper" << endl;
				cout << "--> It's a draw" << endl << endl << endl << endl;
			}
			else if (p2choice == 3)
			{
				cout << "--> Computer has chosen Scissor" << endl;
				cout << "--> Computer is the winner" << endl << endl << endl << endl;
				p2tally++;
			}
			else
			{
				p2error();
			}
		}
		else if (p1choice == 's' || p1choice == 'S')
		{
			cout << "--> " << p1 << " has chosen Scissor" << endl;
			p2choice = rand() % 3 + 1;
			if (p2choice == 1)
			{
				cout << "--> Computer has chosen Rock" << endl;
				cout << "--> Computer is the winner" << endl << endl << endl << endl;
				p2tally++;
			}
			else if (p2choice == 2)
			{
				cout << "--> Computer has chosen Paper" << endl;
				cout << "--> " << p1 << " is the winner" << endl << endl << endl << endl;
				p1tally++;
			}
			else if (p2choice == 3)
			{
				cout << "--> Computer has chosen Scissor" << endl;
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
	system("cls");
	// tally
	cout<<"Scores:\n"<<p1<<" : "<<p1tally<<"\nComputer : "<<p2tally<<endl<<endl;
	if (p1tally > p2tally)
	{
		cout << p1 << " is the winner" << endl;
	}
	else if (p1tally < p2tally)
	{
		cout << "Computer is the winner" << endl;
	}
	else
	{
		cout << "It's a draw" << endl;
	}
	system("pause");
	repeat();
}

// Code by Aadith Sukumar (https://www.github.com/aadi1011)
void RPS::exitgame()
{
	system("cls");
	cout << endl << endl << "Thank you for playing, " << p1 << " and " << p2 << "I hope you had a great time" << endl << endl;
	system("pause");
	exit(0);
}

int main()
{
	int introchoice, gamemode;
	char exitchoice;
	cout << "Welcome to Rock, Paper, Scissor" << endl << endl;
	cout<<"1. Start\n2. About\n3. Exit\n";
	cin >> introchoice;
	if (introchoice == 1)
	{
		system("cls");
		cout<<"Choose gamemode: \n1. Player vs Player\n2. Player vs Computer\n";
		cin>>gamemode;

		if (gamemode == 1)
		{
			RPS game1;
			game1.username();
		}
		else if (gamemode == 2)
		{
			RPS game2;
			game2.computer();
		}
		else
		{
			cout << "Invalid input, please try again" << endl;
			system("pause");
			system("cls");
			main();
		}
	}
	else if (introchoice == 2)
	{
		system("cls");
		cout << "This is a simple game of Rock, Paper, Scissor" << endl << endl;
		cout << "The rules are simple, you have to choose either Rock, Paper or Scissor" << endl << endl;
		cout << "Rock beats Scissor, Scissor beats Paper and Paper beats Rock" << endl << endl;
		cout << "Created by Aadith Sukumar" << endl;
		cout<<"Github: https://www.github.com/aadi1011"<<endl;
		cout<<"Game source code available at: https://www.github.com/aadi1011/Rock-Paper-Scissor"<<endl;

		system("pause");
		system("cls");
		main();
	}
	else if (introchoice == 3)
	{
		system("cls");
		cout << " Are you sure? (y/n)" << endl << endl;
		cin >> exitchoice;
		if (exitchoice == 'Y' || exitchoice == 'y')
		{
			system("cls");
			cout << "I wish you had played! See you next time..." << endl << endl;
			system("pause");
			exit(0);
		}
		else if (exitchoice == 'N' || exitchoice == 'n')
		{
			system("cls");
			main();
		}
		else
		{
			system("cls");
			cout << "Invalid option selected, please select either Y or N" << endl << endl;
			main();
		}

		system("pause");
		exit(0);
	}
	else
	{
		system("cls");
		cout << "Invalid option selected, please select either 1, 2 or 3" << endl << endl;
		main();
	}

	return 0;
}// Code by Aadith Sukumar (https://www.github.com/aadi1011)

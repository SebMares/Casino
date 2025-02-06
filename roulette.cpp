#include <iostream>
#include <cstdlib>
#include <ctime>
#include "casino.h"

using namespace std;

void roulette()
{
	srand(time(0)); //Seed the random number generator

	int balance = 100; //Initial balance
	int bet;
	int betType;
	int result;
	char playAgain;

	cout << "\nWelcome to the Roulette Game!" << endl;

	do {
		cout << "Your current balance is: $" << balance << endl;
		cout << "Place your bet (1-36 for a number, 37 for Red, 38 for Black, 39 for Even, 40 for Odd): ";
		cin >> betType;

		if (betType < 1 || betType > 40) {
			cout << "Invalid bet type. Please try again." << endl;
			continue;
		}

		cout << "Enter your bet amount: ";
		cin >> bet;

		if (bet > balance) {
			cout << "You don't have enough balance to place this bet." << endl;
			continue;
		}

		//Spin the wheel
		result = rand() % 37; //Random number between 0 and 36
		cout << "The wheel landed on: " << result;

		//Determine the color
		string color;
		if (result == 0) 
		{
			color = "Green";
		}
		else
		{
			int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
			bool isRed = false;
			
			for (int i = 0; i < 18; ++i)
			{
				if (result == redNumbers[i])
				{
					isRed = true;
					break;
				}
			}
			color = isRed ? "Red" : "Black";
		}
		
		cout << " (" << color << ")" << endl;

		//Check if the player's bet is correct
		bool win = false;
		
		if (betType >= 1 && betType <= 36) //Bet on a specific number
		{
			win = (betType == result);
		}
		else if (betType == 37) //Bet on Red
		{ 
			win = (color == "Red");
		}
		else if (betType == 38) //Bet on Black
		{
			win = (color == "Black");
		}
		else if (betType == 39) //Bet on Even
		{
			win = (result != 0 && result % 2 == 0);
		} 
		else if (betType == 40) //Bet on Odd
		{ 
			win = (result % 2 != 0);
		}

		//Calculate winnings or losses
		if (win)
		{
			int winnings = bet * (betType >= 1 && betType <= 36 ? 35 : 1); //Payout for number bet is 35:1, others 1:1
			balance += winnings;
			cout << "Congratulations! You won $" << winnings << "!" << endl;
		}
		else 
		{
			balance -= bet;
			cout << "Sorry, you lost $" << bet << "." << endl;
		}

		if (balance <= 0) 
		{
			cout << "You're out of money! Game over." << endl;
			break;
		}

		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thanks for playing! Your final balance is: $" << balance << endl;

}



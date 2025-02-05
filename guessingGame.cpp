#include <iostream>
#include <cstdlib>
#include <ctime>
#include "casino.h"

using namespace std;

void guessingGame() {
    int guess;
    int number;
    srand(time(0));
    number = rand() % 100 + 1;

    cout << "Welcome to the Guessing Game!\n";
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    if (guess == number) 
    {
        cout << "Congratulations! You guessed it right!\n";
    }
    else
    {
        cout << "Sorry, the number was " << number << ". Better luck next time!\n";
    }
}

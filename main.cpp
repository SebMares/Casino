#include <iostream>

using namespace std;

int main() {
    int choice;

    cout << "Welcome to the Casino!\n";
        
    while (true)
    {
        cout << "\nChoose a game to play:\n";
        cout << "1. Slot Machine\n";
        cout << "2. Roulette\n";
        cout << "3. Guessing Game\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                slotMachine();
                break;
            case 2:
                roulette();
                break;
            case 3:
                guessingGame();
                break;
            case 4:
                cout << "Thanks for playing! Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

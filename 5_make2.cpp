/*
2.  Random Number Guessing Game

Write a program that generates a random number between 1 and 100 and asks the user to guess what the number is.  

If the user's guess is higher than the random number, the program should display "Too high, try again."  

If the user's guess is lower than the random number the program should display "Too low, try again."  

The program should use a do-while loop that repeats until the user guesses the number correctly.  

The program should also employ a while loop that keeps track of the number of guesses made by the user and, once the user guesses the number correctly, displays the number of guesses the user made.
 
*/

#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    srand(time(0));  // seed the random generator
    int randomNum = rand() % 100 + 1;  // random number between 1 and 100
    int guess;
    int guessCount = 0;

    cout << "Guess the random number between 1 and 100!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        guessCount++;

        if (guess > randomNum) {
            cout << "Too high, try again." << endl;
        }
        else if (guess < randomNum) {
            cout << "Too low, try again." << endl;
        }
        else {
            cout << "Correct! The number was " << randomNum << "." << endl;
            cout << "You guessed it in " << guessCount << " attempts." << endl;
        }
    } while (guess != randomNum);

    return 0;
}
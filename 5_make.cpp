/*
Complete the following programs; when finished take a screen capture of the output from your running program and package it with your .cpp file. Submit a zipped folder with your work.

1.  Apartment Building

A brand new 16 floor apartment building is wrapping up construction and it is time for the building to start bringing in residents. Each floor can hold a maximum of 6 residents (it's a really pricey building).

Set up a loop to display the number of each floor, and ask the user how many apartments are occupied. Do not accept numbers greater than 6 for the number of occupied apartments.

When the loop is complete have it total up the number of occupied apartments (this should be a running total throughout the loops iterations).

Display the total number of rooms, the number of occupied rooms, the number of unoccupied rooms, and the percentage of occupied rooms, all with appropriate labels and spacing.

NOTE: It is traditional that American buildings do not have a 13th floor!  The loop should skip the entire 13th iteration.

INPUT VALIDATION: Remember not to accept numbers less than 0 or greater than 6 for the number of occupied rooms per floor.*/


#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    const int FLOORS = 16;
    const int MAX_OCCUPIED = 6;
    int totalOccupied = 0;
    int totalRooms = FLOORS * MAX_OCCUPIED;  // initially include all floors
    int occupied;
    
    // Subtract out the 13th floor since it does not exist
    totalRooms -= MAX_OCCUPIED;

    for (int floor = 1; floor <= FLOORS; ++floor) {
        if (floor == 13) {
            continue; // skip the 13th floor
        }

        cout << "Enter number of occupied apartments on floor " << floor
             << " (0-" << MAX_OCCUPIED << "): ";
        cin >> occupied;

        // input validation
        while (occupied < 0 || occupied > MAX_OCCUPIED) {
            cout << "Invalid input. Please enter a value between 0 and "
                 << MAX_OCCUPIED << ": ";
            cin >> occupied;
        }

        totalOccupied += occupied;
    }

    int unoccupied = totalRooms - totalOccupied;
    double percent = (static_cast<double>(totalOccupied) / totalRooms) * 100.0;

    cout << "\n---- Apartment Building Report ----\n";
    cout << "Total rooms:       " << totalRooms << endl;
    cout << "Occupied rooms:    " << totalOccupied << endl;
    cout << "Unoccupied rooms:  " << unoccupied << endl;
    cout << fixed << setprecision(2);
    cout << "Percent occupied:  " << percent << "%" << endl;

    return 0;
}



 
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
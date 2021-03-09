#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

/**
 * A game of Higher/Lower
 */
int main() {
    int goal;
    int guess;
    string userInput;

    srand (time(NULL)); //initialize random seed

    while(true) {
        printf("Let's play a game of Higher/Lower.\n");
        printf("I'm thinking of a number between 1 and 100.\n");
        goal = rand() % 100 + 1;
        guess = 100;
        while (goal != guess) {
            printf("What's your guess? ");
            getline(cin, userInput);

            try { //check if input is valid
                guess = stoi(userInput);
            } catch(const invalid_argument& ia) {
                printf("Invalid input! Please enter an integer.\n");
                continue;
            }

            if (goal > guess) {
                printf("Higher!\n");
            } else if (goal < guess) {
                printf("Lower!\n");
            }
        }

        printf("You got it!\n");
        printf("Would you like to play again?: ");
        getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[0] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }
    printf("Bye!\n");
    return 0;
}
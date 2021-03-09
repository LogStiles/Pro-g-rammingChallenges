#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

enum RPS {rock, paper, scissors};

/**
 * Plays a game of rock, paper, scissors with the user
 */
int main() {
    srand (time(NULL)); //initialize random seed
    printf("Let's play Rock, Paper, Scissors!\n");
    string userInput;
    RPS playerChoice;
    int numberOfOptions = 3;
    RPS compChoice;

    while(true) {
        while(true) {
            compChoice = static_cast<RPS>(rand() % numberOfOptions);
            printf("Choose Rock, Paper, or Scissors: ");
            getline(cin, userInput);
            if (userInput[0] == 'r' or userInput[0] == 'R') {
                printf("You chose rock.\n");
                playerChoice = rock;
                break;
            }
            else if (userInput[0] == 's' or userInput[0] == 'S') {
                printf("You chose scissors.\n");
                playerChoice = scissors;
                break;
            }
            else if (userInput[0] == 'p' or userInput[0] == 'P') {
                printf("You chose paper.\n");
                playerChoice = paper;
                break;
            } else {
                printf("That's not a choice!\n");
            }
        }

        if (compChoice == rock) {
            printf("I chose rock!\n");
        } else if (compChoice == scissors) {
            printf("I chose scissors!\n");
        } else {
            printf("I chose paper!\n");
        }

        if (playerChoice == compChoice) {
            printf("We tied!\n");
        }
        else if ((playerChoice == rock and compChoice == scissors) or (playerChoice == scissors and compChoice == paper) or (playerChoice == paper && compChoice == rock)) {
            printf("You won!\n");
        } else {
            printf("I won!\n");
        }

        printf("Would you like to play again?: ");
        getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[0] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }

    printf("Bye!\n");
    return 0;
}
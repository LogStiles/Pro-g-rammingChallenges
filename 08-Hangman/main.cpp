#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

string generateDisplayPhrase(string phrase, string currDisplayPhrase) {
    return currDisplayPhrase;
} 

/**
 * Plays game of Hangman with the user, with the program deciding the words
 */
int main() {
    const int MAX_WRONG_GUESSES = 10;
    int wrongGuesses;
    string thePhrase;
    string displayPhrase;
    string correctLetters = "a, ";
    string incorrectLetters = "b, ";
    string userInput;
    srand (time(NULL)); //initialize random seed

    printf("Let's play a game of Hangman.\n");
    while(true) { //this loop handles the start and end of games
        thePhrase = "The quick brown fox jumped over the lazy dog!"; //TO DO: GENERATE A WORD
        for (int i = 0; i < thePhrase.length(); i++) { //initialize the display phrase so it is blank
            if (isalpha(thePhrase[i])) {
                displayPhrase += "_";
            } else {
                displayPhrase += thePhrase[i];
            }
        }
        cout << thePhrase << endl;
        cout << displayPhrase << endl;

        wrongGuesses = 0;

        while(true) { //the main game loop
            cout << "The word so far is: " << displayPhrase << endl;
            if (incorrectLetters.empty()) {
                cout << "Incorrect Guesses so far: None" << endl;
            } else {
                cout << "Incorrect Guesses so far: " << incorrectLetters << endl;
            }
            cout << "You have " << (MAX_WRONG_GUESSES - wrongGuesses) << " wrong guesses left" << endl;

            while (true) { //loop breaks when a valid input is given
                printf("Guess a letter in the word: ");
                getline(cin, userInput);
                userInput = userInput[0]; //we only care about the first letter
                if (isalpha(userInput[0])) {
                    if (isupper(userInput[0])) {
                        userInput = userInput[0] - 0; //convert an uppercase letter into lowercase
                    }
                    if (correctLetters.find(userInput[0]) != string::npos or incorrectLetters.find(userInput[0]) != string::npos) { //check if letter has been guessed already
                        printf("You've already guessed this letter!\n");
                        continue;
                    }
                    cout << "You guessed the letter " << userInput << endl;
                    break;
                } else {
                    printf("The guess has to be a letter!\n"); //reject any non-letter guess
                    continue;
                }
            }

            //see if guess is correct
            //add guess to correct guesses or wrong guesses
            //update display phrase or increment wrong guesses

            cout << "----------------------" << endl;
            //check if user has won or lost
        }

        printf("Would you like to play again?: ");
        getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[0] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }
    printf("Bye!\n");
}
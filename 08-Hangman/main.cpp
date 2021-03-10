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
    string userInput;
    srand (time(NULL));

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

        }

        printf("Would you like to play again?: ");
        getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[0] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }
    printf("Bye!\n");
}
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

/**
 * Plays game of Hangman with the user, with the program deciding the words
 */
int main() {
    const int MAX_WRONG_GUESSES = 10;
    int wrongGuesses;
    string thePhrase;
    string displayPhrase;
    string correctLetters;
    string incorrectLetters;
    string userInput;
    
    //srand (time(NULL)); //initialize random seed

    printf("Let's play a game of Hangman.\n");
    while(true) { //this loop handles the start and end of games
        thePhrase = "Robin Williams!"; //to do: generate a word randomly

        displayPhrase.clear(); //clear the display phrase in case it's being reused from another game
        for (int i = 0; i < thePhrase.length(); i++) { //initialize the display phrase so it is blank
            if (isalpha(thePhrase[i])) {
                displayPhrase += "_";
            } else {
                displayPhrase += thePhrase[i];
            }
        }

        wrongGuesses = 0;
        correctLetters.clear();
        incorrectLetters.clear();

        while(true) { //the main game loop
            cout << "The phrase so far is: " << displayPhrase << endl;
            if (incorrectLetters.empty()) {
                cout << "Incorrect Guesses so far: None" << endl;
            } else {
                cout << "Incorrect Guesses so far: " << incorrectLetters << endl;
            }
            cout << "You have " << (MAX_WRONG_GUESSES - wrongGuesses) << " wrong guesses left" << endl;

            while (true) { //loop breaks when a valid input is given
                printf("Guess a letter in the phrase: ");
                std::getline(cin, userInput);
                userInput = userInput[0]; //we only care about the first letter
                if (isalpha(userInput[0])) {
                    if (isupper(userInput[0])) {
                        userInput = userInput[0] + 32; //convert an uppercase letter into lowercase
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
            if (thePhrase.find(userInput[0]) != string::npos or thePhrase.find(userInput[0] - 32) != string::npos) { //if the the guess exists in the phrase in the uppercase or lowercase
                printf("Correct!\n");
                correctLetters += userInput[0];
                //update display phrase
                for (int i = 0; i < thePhrase.length(); i++) { //for each character in phrase
                    if (thePhrase[i] == userInput[0] or thePhrase[i] == (userInput[0] - 32)) { //if the current character is the same as the new character (in uppercase or lower case)
                        displayPhrase.replace(i, 1, thePhrase.substr(i, 1)); //replace the corresponding blank spot
                    }
                }
            } else {
                printf("Wrong!\n");
                wrongGuesses += 1;
                incorrectLetters.append(userInput); //userInput should only be one character at this point
            }

            cout << "----------------------" << endl;
        
            if (wrongGuesses == MAX_WRONG_GUESSES) { //check if the user lost
                printf("You lost! Better luck next time.\n");
                cout << "The phrase was: " << thePhrase << endl;
                break; //the current game has ended
            }
            if (displayPhrase.compare(thePhrase) == 0) { //check if the user won
                printf("You won!\n");
                cout << "The phrase was: " << thePhrase << endl;
                break; //the current game has ended
            }
        }

        printf("Would you like to play again?: ");
        std::getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[0] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }
    printf("Bye!\n");
}
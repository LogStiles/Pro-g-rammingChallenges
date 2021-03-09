#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

const char* upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* lowerAlpha = "abcdefghijklmnopqrstuvwxyz";

string caeserDecrypt(string message, int key) {
    string decoding;
    int charValue;

    for (int i = 0; i < message.length(); i++) {
        if (isupper(message[i])) {
            //The ASCII value of 'A' is 65, so we want to map this uppercase character to a range of 0-25
            int charValue = (int)message[i] - 65;
            decoding += upperAlpha[(charValue + (26 - key)) % 26];
        }
        else if (islower(message[i])) {
            //The ASCII value of 'a' is 97, so we want to map this uppercase character to a range of 0-25
            int charValue = (int)message[i] - 97;
            decoding += lowerAlpha[(charValue + (26 - key)) % 26];
        } else { //character is not in the alphabet so just insert it into the string
            decoding += message[i];
        }
    }

    return decoding;
}

string caeserEncrypt(string message, int key) {
    string encoding;
    int charValue;

    for (int i = 0; i < message.length(); i++) {
        if (isupper(message[i])) {
            //The ASCII value of 'A' is 65, so we want to map this uppercase character to a range of 0-25
            int charValue = (int)message[i] - 65;
            encoding += upperAlpha[(charValue + key) % 26];
        }
        else if (islower(message[i])) {
            //The ASCII value of 'a' is 97, so we want to map this uppercase character to a range of 0-25
            int charValue = (int)message[i] - 97;
            encoding += lowerAlpha[(charValue + key) % 26];
        } else { //character is not in the alphabet so just insert it into the string
            encoding += message[i];
        }
    }
    return encoding;
}

/**
 * Takes a key and string from the user and encrypts or decrypts it using a Caesar Cipher
 */
int main() {
    printf("Let's use a Caeser Cipher!\n");
    string userInput;
    string message;
    int key;

    printf("Enter a message: ");
    getline(cin, message);

    while(true) { //loop will break when a valid key is given
        printf("Enter a key: ");
        getline(cin, userInput);
        try {
            key = stoi(userInput); //check if input is valid
            break;
        } catch(const invalid_argument& ia) {
            printf("Please enter a number!\n");
        }
    }

    while(true) { //loop will break when a valid choice is given
        printf("Would you like to encrpyt this or decrpyt this?: ");
        getline(cin, userInput);
        if (userInput[0] == 'e' or userInput[0] == 'E') {
            cout << caeserEncrypt(message, key) << endl;
            break;
        } else if (userInput[0] == 'd' or userInput[0] == 'D') {
            cout << caeserDecrypt(message, key) << endl;
            break;
        } else {
            printf("That's not an option!\n");
        }
    }

    return 0;
}
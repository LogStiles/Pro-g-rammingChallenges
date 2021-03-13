#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * Calculates the compatibility between two names
 * Adds the values of two strings and prints the value of the sum % 101
 */
int main() {
    string firstName;
    string secondName;
    int compatibility = 0;

    printf("What's your name?: ");
    getline(cin, firstName);
    printf("What's your crush's name? ");
    getline(cin, secondName);

    for (int i = 0; i < firstName.length(); i++) { //add values of first name's characters
        compatibility += (int)firstName[i];
    }

    for (int i = 0; i < secondName.length(); i++) { //add values of second name's characters
        compatibility += (int)secondName[i];
    }

    compatibility = compatibility % 101; //take compatibility mod 101 so it is a value between 1 and 100

    cout << "The compatibility between " << firstName << " and " << secondName << " is " << compatibility << "%!" << endl;

    return 0;
}
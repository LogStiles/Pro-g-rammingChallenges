#include <iostream>
#include <string>
using namespace std;

struct Date { int d; int m; int y;}; //A struct to represent a single date, with a day, month, and year

/**
 * Asks for the user's birtday and then calculates the number of seconds between then and now
 */
int main() {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date birthday = {1, 1, 0}; //values are just placeholders
    int tempInt;
    string userInput;

    printf("I'll calculate your age in seconds. Just let me learn about your birthday!\n");
    
    while(true) { //this loop will break when the user gives a valid month;
        printf("What month were you born in? (A number between 1 and 12): ");
        getline(cin, userInput);

        try {
            tempInt = stoi(userInput);
        } catch (const invalid_argument ia) { //check if input was a number
            printf("Please enter a number!\n");
            continue;
        }

        if (0 < tempInt and tempInt < 13) {
            birthday.m = tempInt;
            break;
        } else {
            printf("Please enter a number between 1 and 12!\n");
        }
    }

    while(true) { //this loop will break when the user gives a valid day of the month
        printf("What month were you born in? (There are %d days in your month): ", monthDays[birthday.m - 1]);
        getline(cin, userInput);

        try {
            tempInt = stoi(userInput);
        } catch (const invalid_argument ia) { //check if input was a number
            printf("Please enter a number!\n");
            continue;
        }

        if (0 < tempInt and tempInt <= monthDays[birthday.m - 1]) {
            birthday.d = tempInt;
            break;
        } else {
            printf("Please enter a number between 1 and %d!\n", monthDays[birthday.m - 1]);
        }
    }

    while(true) { //this loop will break when the user gives a valid year
        printf("What year were you born in?: ", monthDays[birthday.m - 1]);
        getline(cin, userInput);

        try {
            tempInt = stoi(userInput);
        } catch (const invalid_argument ia) { //check if input was a number
            printf("Please enter a number!\n");
            continue;
        }

        if (-1 < tempInt) { 
            birthday.y = tempInt;
            break;
        } else {
            printf("Please enter a year in A.D!\n", monthDays[birthday.m - 1]);
        }
    }

    printf("The month was %d The day was %d The year was %d\n", birthday.m, birthday.d, birthday.y);
}
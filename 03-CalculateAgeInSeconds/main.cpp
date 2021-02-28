#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Date { int d; int m; int y;}; //A struct to represent a single date, with a day, month, and year
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * Fills out a Date struct with information about the current day
 * date - a pointer to the Date struct we wish to fill out
 */
void getTodaysDate(Date* date) {
    time_t t = time(0);
    tm* now = localtime(&t);
    date->d = now->tm_mday;
    date->m = now->tm_mon + 1;
    date->y = 1900 + now->tm_year;
}

/**
 * Counts the number of days between the given date and January 1st, 0 AD
 * date - a pointer to a Date struct
 * Returns the number of days calculated
 */
int countDays(Date* date) {
    int numDays = date->y * 365; //start with the number of days from previous years
    for (int i = 0; i < date->m - 1; i++) { //Add the days from the previous months this year
        numDays += monthDays[i];
    }
    numDays += date->d; //Add the days from this month
    return numDays;
}

/**
 * Asks for the user's birtday and then calculates the number of seconds between then and now
 */
int main() {
    Date birthday;
    Date today;
    int tempInt;
    string userInput;

    getTodaysDate(&today);

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
        printf("What day were you born on? (There are %d days in your month): ", monthDays[birthday.m - 1]);
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
        printf("What year were you born in?: ");
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

    int diffDays = countDays(&today) - countDays(&birthday); //the number of days between today and the user's birthday
    int ageInSeconds = diffDays * 24 * 60 * 60;
    printf("You are %d seconds old\n", ageInSeconds);
}
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Date { int d; int m; int y;}; //A struct to represent a single date, with a day, month, and year

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
 * Compares two dates to see which date occurs later
 * date1, date2 - two Date structs we are comparing
 * Returns 1 if date2 is a later date than date1, -1 if it is the sooner date, and 0 if they are the same date
 */
int isDateLater(Date* date1, Date* date2) {
    if (date1->y < date2->y) { //if date2's year occurs later, it is the later date
        return 1;
    } else if (date1->y > date2->y) { //if date2's year occurs sooner, it is not the later date
        return -1;
    } else { //if the two years are equal, we need more information

        if (date1->m < date2->m) { //if date2's month occurs later, it is the later date
            return 1;
        } else if (date1->m > date2->m) { //if date2's month occurs sooner, it is not the later date
            return -1;
        } else { //if the two months are equal, we need more information

            if (date1->d < date2->d) { //if date2's day occurs later, it is the later date
                return 1;
            } else if (date1->d > date2->d) { //if date2's day occurs sooner, it is not the later date
                return -1;
            } else { //if the two months are equal, they are the same date
                return 0;
            }
        }
    }
}

/**
 * Asks for the user's birtday and then calculates the number of seconds between then and now
 */
int main() {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date birthday;
    Date today;
    int tempInt;
    string userInput;

    getTodaysDate(&today);

    printf("%d %d %d\n", today.d, today.m, today.y);

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

    int dateComparison = isDateLater(&birthday, &today);
    cout << dateComparison << endl;
}
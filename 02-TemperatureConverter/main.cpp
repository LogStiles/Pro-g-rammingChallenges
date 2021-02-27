#include <iostream>
#include <string>
using namespace std;

/**
 * Asks for a temperature and converts it to another unit of measurement.
 * Capable of changing Fahrenheit to Celcius and Celcius to Fahrenheit
 */
int main() {
    float temp = 0.0f;
    float newTemp = 0.0f;
    string userInput;

    while(true) {
        printf("Give me a temperature and I will convert it\n");
        printf("First tell me the temperature and then I'll ask for the units: ");
        getline(cin, userInput);

        try {
            temp = stof(userInput); //check if input is valid
        } catch(const invalid_argument& ia) {
            printf("Please enter a number!\n");
            continue;
        }

        while(true) { //loop will break when valid unit is given
            printf("Was that temperature in Celsius or Fahrenheit?: ");
            getline(cin, userInput);
            if (userInput[0] == 'c' or userInput[0] == 'C') { //if the input was celcius, convert to fahrenheit
                newTemp = (1.8*temp) + 32.0;
                printf("%f degrees Celcius is %f degrees Fahrentheit\n", temp, newTemp);
                break;
            } else if (userInput[0] == 'f' or userInput[0] == 'F') { //if the input was fahrenheit, convert to celcius
                newTemp = (temp - 32.0) / 1.8;
                printf("%f degrees Fahrenheit is %f degrees Celcius\n", temp, newTemp);
                break;
            } else {
                printf("Please give an accepted unit of temperature.\n");
            }
        }

        printf("Would you like to convert another temperature?: ");
        getline(cin, userInput); 
        if (userInput[0] == 'n' or userInput[1] == 'N') { //if the answer starts with 'N' we'll assume the answer was "No"
            break;
        }
    }

    printf("Bye!");
}
#include <iostream>
#include <string>
using namespace::std;

/**
 * An infinite loop that asks for a string and then returns the reverse of it
 */
int main() {
    string stringToReverse;

    while(true) {
        cout << "Type a string and I will reverse it: ";
        getline(cin, stringToReverse);
        for (int i = 0; i < stringToReverse.size()/2; i++) {
            //printf("%d %d\n", i, stringToReverse.size() - i - 1);
            swap(stringToReverse[i], stringToReverse[stringToReverse.size() - i - 1]);
        }
        cout << stringToReverse << endl;
    }
    return 0;
}
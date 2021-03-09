#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Loads first_names.txt and last_names.txt and then randomly generates a full name
 */
int main() {
    srand (time(NULL)); //initialize random seed
    vector<string> first_names;
    vector<string> last_names;
    string name;
    string fc;
    ifstream file;

    file.open("first_names.txt");
    if (!file) {
        printf("Unable to open first_names.txt\n");
        return -1;
    }
    while (getline(file,name)) {
        first_names.push_back(name);
    }
    file.close();

    file.open("last_names.txt");
    if (!file) {
        printf("Unable to open last_names.txt\n");
        return -1;
    }
    while (getline(file,name)) {
        last_names.push_back(name);
    }
    file.close();

    name = first_names.at(rand() % (first_names.size() - 1)) + " " + (last_names.at(rand() % (last_names.size() - 1)));
    cout << "Your generated name is " << name << "!" << endl;
    return 0;
}
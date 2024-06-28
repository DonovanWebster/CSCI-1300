#include <iostream>

using namespace std;

void printEligible(string names[], int ages[], int numDrivers) {
    for (int i = 0; i < numDrivers; i++) {
        if (ages[i] >= 25) {
            cout << names[i] << " " << ages[i] << endl;
        }
    }
}

int main() {

    int numDrivers = 4;
    string names[numDrivers] = {"Mark", "Tom", "Anna", "Jules"};
    int ages[numDrivers] = {49, 16, 28, 21};
    printEligible(names, ages, numDrivers);

    return 0;

}
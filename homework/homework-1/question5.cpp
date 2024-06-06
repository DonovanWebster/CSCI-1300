// Homework 1 - Problem 5

#include <iostream>

using namespace std;

int main() {

    int knuts, sickles, galleons;
    int sickleRemainder, galleonsRemainder;

    cout << "Enter the number of knuts:" << endl;
    cin >> knuts;

    galleons = knuts / (17 * 29);
    galleonsRemainder = knuts % (17 * 29);
    sickles = galleonsRemainder / 29;
    sickleRemainder = galleonsRemainder % 29;
    knuts = sickleRemainder;

    cout << galleons << " Galleon(s) " << sickles << " Sickle(s) " << knuts << " Knut(s)" << endl;

    return 0;

}
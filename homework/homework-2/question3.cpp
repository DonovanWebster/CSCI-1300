// Homework 2 - Problem 3

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int ducks;
    double discount, total;

    cout << "How many ducks would you like to order?" << endl;
    cin >> ducks;

    if (ducks <= 0) {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    if (ducks > 500) {
        discount = 0.5;
    } else if (ducks > 100) {
        discount = 0.8;
    } else if (ducks > 20) {
        discount = 0.9;
    } else {
        discount = 1.0;
    }

    total = discount * (0.5 * ducks);

    cout << "Your total is $" << fixed << setprecision(2) << total << endl;

    return 0;

}
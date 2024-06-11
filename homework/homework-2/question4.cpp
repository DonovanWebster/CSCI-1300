// Homework 2 - Problem 4

#include <iostream>

using namespace std;

int main() {

    double price1, price2, price3;
    bool increasing = false, decreasing = false;

    cout << "Enter stock prices over last 3 weeks" << endl;
    cin >> price1 >> price2 >> price3;

    if (price1 <= 0 || price2 <= 0 || price3 <= 0) {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    if (price1 > price2 && price2 > price3) {
        decreasing = true;
    }
    if (price1 < price2 && price2 < price3) {
        increasing = true;
    }

    if (increasing) {
        cout << "The value is rising!" << endl;
        return 0;
    }
    if (decreasing) {
        cout << "The value is tanking." << endl;
        return 0;
    }

    cout << "Neither" << endl;

    return 0;

}
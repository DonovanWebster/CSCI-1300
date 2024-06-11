// Homework 2 - Problem 7

#include <iostream>

using namespace std;

int main() {

    int num, sum = 0;

    cout << "Enter a positive integer:" << endl;
    cin >> num;
    if (num <= 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    while (num % 3 != 0) {
        num--;
    }

    while (num > 0) {
        sum += num;
        num -= 3;
    }

    cout << "Sum: " << sum << endl;
    
    return 0;

}
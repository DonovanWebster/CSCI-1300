// Homework 3 - Problem 2

#include <iostream>
#include <cmath>

using namespace std;

long int getNextNumInSequence(long int n) {
    long int num;
    if (n % 2 == 0) {
        num = floor(sqrt(n));
    } else {
        num = floor(pow(sqrt(n), 3));
    }
    return num;
}

int main() {

    long int num;
    cout << "Enter a positive integer:" << endl;
    cin >> num;
    if (num <= 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    while (num > 1) {
        cout << num << endl;
        num = getNextNumInSequence(num);
    }

    cout << num;

    return 0;

}
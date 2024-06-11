// Homework 2 - Extra Credit

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    string invalidInput = "Please enter a valid input.\n";
    int score1, score2, score3;
    double average;

    cout << "Enter practicum 1 score:" << endl;
    cin >> score1;
    if (score1 < 0) {
        cout << invalidInput;
        return 1;
    }

    cout << "Enter practicum 2 score:" << endl;
    cin >> score2;
    if (score2 < 0) {
        cout << invalidInput;
        return 1;
    }

    cout << "Enter practicum 3 score:" << endl;
    cin >> score3;
    if (score3 < 0) {
        cout << invalidInput;
        return 1;
    }

    average = (score1 + score2 + score3) / 3.0;

    cout << "Practicum average: " << fixed << setprecision(2) << average << endl;

    if (average >= 67.00) {
        cout << "You have a passing practicum average." << endl;
    } else {
        cout << "You can retake practicums during the final." << endl;
    }
    
    return 0;

}
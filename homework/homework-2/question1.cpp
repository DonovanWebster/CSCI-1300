#include <iostream>

using namespace std;

int main() {

    int age;
    cout << "How old are you?" << endl;
    cin >> age;
    if (age < 0) {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    if (age >= 18) {
        cout << "You can buy a ticket! Good luck." << endl;
        return 0;
    }

    cout << "You cannot buy a lottery ticket yet." << endl;

    return 0;

}
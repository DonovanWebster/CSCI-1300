#include <iostream>

using namespace std;

int main() {

    int length;
    cout << "Enter the triangle side length:" << endl;
    cin >> length;

    if (length < 0) {
        cout << "Invalid input" << endl;
        return 1;
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;

}
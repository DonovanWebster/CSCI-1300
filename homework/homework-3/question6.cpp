// Homework 3 - Extra Credit

#include <iostream>

using namespace std;

void print(int n, int l) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    for (int i = 0; i < (l-2*n); i++) {
        cout << " ";
    }
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

int main() {

    cout << "Enter the length:" << endl;
    int length;
    cin >> length;

    int width = (2 * length) + 1;

    for (int i = length; i > 0; i--) {
        print(i, width);
    }
    for (int i = length - (length - 2); i < length + 1; i++) {
        print(i, width);
    }

    return 0;

}
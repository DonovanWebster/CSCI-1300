// Homework 3 - Problem 1

#include <iostream>
#include <cctype>

using namespace std;

string flipCase(string str, int len) {
    string out = "";
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                out += toupper(str[i]);
            } else {
                out += tolower(str[i]);
            }
        } else {
            out += str[i];
        }
    }
    return out;
}

int main() {

    cout << "Enter the string:" << endl;

    string input;
    getline(cin, input);

    cout << flipCase(input, input.length());

    return 0;

}
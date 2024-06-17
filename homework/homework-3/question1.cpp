// Homework 3 - Problem 1

#include <iostream>
#include <cctype>

using namespace std;

int main() {

    cout << "Enter the string:" << endl;

    string input, output = "";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            if (islower(input[i])) {
                output += toupper(input[i]);
            } else {
                output += tolower(input[i]);
            }
        } else {
            output += input[i];
        }
    }

    cout << output;

    return 0;

}
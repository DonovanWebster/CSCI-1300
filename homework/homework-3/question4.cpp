// Homework 3 - Problem 4

#include <iostream>

using namespace std;

int main() {

    cout << "Enter the search string:" << endl;
    string str, sub_str;
    cin >> str;
    cout << "Enter the substring to be searched:" << endl;
    cin >> sub_str;

    int count = 0;
    for (int i = 0; i < str.length() - sub_str.length(); i++) {
        if (str.substr(i, sub_str.length()) == sub_str) {
            count++;
        }
    }

    cout << "Number of occurrences: " << count << endl;

    return 0;

}
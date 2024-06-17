// Homework 3 - Problem 5

#include <iostream>

using namespace std;

int main() {

    string alpha = "zyxwvutsrqponmlkjihgfedcba";

    cout << "Enter the height:" << endl;
    int height;
    cin >> height;
    if (height <= 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    int numChars = 0;
    int j = height;
    for (int i = 0; i < height; i++) {
        numChars += j;
        j--;
    }

    int repeats = numChars / alpha.length();
    int remainder = numChars % alpha.length();

    string out = "";

    for (int i = 0; i < repeats; i++) {
        out += alpha;
    }
    out += alpha.substr(0, remainder);

    int start = 0;
    for (int i = 0; i < height; i++) {
        string sub = out.substr(start, height - i);
        cout << out.substr(start, height - i) << endl;
        start += height - i;
    }

    return 0;

}
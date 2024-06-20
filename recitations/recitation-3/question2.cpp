#include <iostream>

using namespace std;

int main() {

    string question = "Please enter an integer between 1 and 100:\n";
    int num, entryCount = 0, divisibleCount = 0;
    cout << question;
    cin >> num;
    while (1 <= num && num <= 100) {
        if (num % 3 == 0) {
            cout << "divisible by 3" << endl;
            divisibleCount++;
        }
        entryCount++;

        cout << question;
        cin >> num;
    }

    cout << "entries: " << entryCount << endl;
    cout << "divisible by 3: " << divisibleCount << endl;

    return 0;

}
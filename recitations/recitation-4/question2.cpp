#include <iostream>

using namespace std;

string deleteDup(string str) {
    if (str.length() == 0 || str.length() == 1) {
        return "";
    }
    int len = str.length();
    for (int i = 1; i < len; i++) {
        if (str.at(i) == str.at(i - 1)) {
            str.erase(i, 1);
            i--;
            len--;
        }
    }
    return str;
}

int main() {

    string in_str;
    cout << "Please enter a string:" << endl;
    cin >> in_str;

    cout << deleteDup(in_str);

    return 0;
}
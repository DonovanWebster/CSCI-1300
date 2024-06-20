#include <iostream>

using namespace std;

int main() {

    string in_str;
    cout << "Please enter a string:" << endl;
    getline(cin, in_str);

    for (int i = 0; i < int(in_str.length() - 1); i++) {
        cout << in_str[i] << " ";
    }

    cout << in_str[in_str.length() - 1] << endl;

    return 0;

}
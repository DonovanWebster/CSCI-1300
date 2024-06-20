#include <iostream>

using namespace std;

int main() {

    string in_str, out_str;
    int pos1, pos2;

    cout << "Please enter a string:" << endl;
    getline(cin, in_str);
    cout << "Which letters would you like to swap?" << endl;
    cin >> pos1 >> pos2;

    out_str = in_str;
    out_str[pos1] = in_str[pos2];
    out_str[pos2] = in_str[pos1];

    cout << "New string: " << out_str;

    return 0;

}
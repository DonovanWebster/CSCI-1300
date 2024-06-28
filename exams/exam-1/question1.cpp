#include <iostream>
#include <cctype>

using namespace std;

bool isvowel(char ch) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < 6; i++) {
        if (ch == vowels[i]) {
            return true;
        }
    }
    return false;
}

void stringInfo(string str) {
    string out_str = "";
    int occurences = 0;

    // convert all characters to lowercase
    for (int i = 0; i < int(str.length()); i++) {
        str.at(i) = tolower(str.at(i));
    }

    for (int i = 0; i < int(str.length()); i++) {
        if (isalpha(str.at(i)) && !isvowel(str.at(i))) {
            out_str += str.at(i);
            occurences++;
        }
    }
    cout << "Number of consonants: " << occurences << endl;
    cout << out_str << endl;
}

int main() {

    string str;
    cout << "Please enter a string:" << endl;
    getline(cin, str);

    stringInfo(str);

    return 0;

}
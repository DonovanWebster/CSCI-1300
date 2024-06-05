#include <iostream>

using namespace std;

int getNumVowels(string str) {
    int numVowels = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < 10; j++) {
            if (str[i] == vowels[j]) {
                numVowels++;
                break;
            }
        }
    }
    return numVowels;
}

int main() {

    string input;
    cin >> input;
    cout << "You entered " << getNumVowels(input) << " vowels" << endl;

    return 0;

}
// Homework 4 - Problem 3 - splitString

#include <iostream>

using namespace std;

int split(string inputString, char separator, string arr[], int size) {
    if (inputString.empty()) {
        return 0;
    }
    
    int indeces[size];
    int count = 0;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] == separator) {
            indeces[count] = i;
            count++;
        }
    }
    if (count == 0) {
        arr[0] = inputString;
        return 1;
    }
    
    for (int i = 0; i < count; i++) {
        if (i > size) {
            return -1;
        }
        int j = indeces[0];
        if (i == 0) {
            j = 0;
        }
        for (j; j < indeces[i]; j++) {
            if (inputString[j] != separator) {
                arr[i].push_back(inputString[j]);
            }
        }
    }

    return count;

}

int main() {

string testcase = "ABCDEFG";
char separator = ' ';
int size = 3;
string arr[size];
// numSplits is the value returned by split
int numSplits = split(testcase, separator, arr, size);
cout << "Function returned value: " << numSplits << endl;
cout << "arr[0]:"<< arr[0] << endl;

    return 0;

}
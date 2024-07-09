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

    int end = count + 1;

    if (count >= size) {
        end = size;
    }

    indeces[count] = inputString.length();
    for (int i = 0; i < end; i++) {
        int start, len;
        if (i == 0) {
            start = 0;
            len = indeces[0];
        } else {
            start = indeces[i-1]+1;
            len = indeces[i] - start;
        }
        arr[i] = inputString.substr(start, len);
    }

    if (end == size) {
        return -1;
    }
    
    return count;

}

int main() {

string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
char separator = ',';
int size = 5;
string arr[size];
// numSplits is the value returned by split
int numSplits = split(testcase, separator, arr, size);
cout << "Function returned value: " << numSplits << endl;
for (int i=0 ;i < size; i++){
  cout << "arr["<< i << "]:" << arr[i] << endl;
}

    return 0;

}
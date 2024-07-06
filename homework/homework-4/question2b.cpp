// Homework 4 - Problem 2b - insertConsonants

#include <iostream>
#include <cassert>

using namespace std;

bool insertAfter(char inputCharacters[], int numElements, int size, int index, char charToInsert) {
    if (index >= size || numElements == size) {
        return false;
    }

    char new_arr[size];
    for (int i = 0; i <= index; i++) {
        new_arr[i] = inputCharacters[i];
    }
    new_arr[index + 1] = charToInsert;
    for (int i = index + 1; i < size; i++) {
        new_arr[i + 1] = inputCharacters[i];
    }
    for (int i = 0; i < size; i++) {
        inputCharacters[i] = new_arr[i];
    }

    return true;
}

bool isvowel(char ch) {
    return (ch == 97) || (ch == 101) || (ch == 105) || (ch == 111) || (ch == 117) || (ch == 121);
}

int insertConsonants(char inputCharacters[], int numElements, int size, int numConsonants) {
    if (numElements + numConsonants > size) {
        return numElements;
    }
    
    for (int i = 0; i < size; i++) {
        if (!isvowel(inputCharacters[i])) {
            insertAfter(inputCharacters, numElements, size, i, inputCharacters[i] - 32);
            i++;
        }
    }
    return numElements + numConsonants;
}

int main() {

    // test 1
    int size1 = 5;
    char inputCharacters1[size1] = "cat";
    int numElements1 = 3;
    int numConsonants1 = 2;
    assert(insertConsonants(inputCharacters1, numElements1, size1, numConsonants1) == (numElements1 + numConsonants1));

    // test 2
    int size2 = 9;
    char inputCharacters2[size2] = "apples";
    int numElements2 = 6;
    int numConsonants2 = 4;
    assert(insertConsonants(inputCharacters2, numElements2, size2, numConsonants2) == numElements2);

    return 0;

}
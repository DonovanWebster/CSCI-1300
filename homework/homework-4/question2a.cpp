// Homework 4 - Problem 2a - insertAfter

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

int main() {

    // test 1
    char string1[5] = "cat";
    assert(insertAfter(string1, 3, 5, 2, 's') == true);
    // test 2
    char string2[10] = "Booooooo!";
    assert(insertAfter(string2, 10, 10, 9, '!') == false);

    return 0;

}
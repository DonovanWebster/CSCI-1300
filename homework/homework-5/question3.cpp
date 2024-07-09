#include <iostream>
#include <fstream>
#include <cassert>

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

    if (count > size) {
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

    if (count > size) {
        return -1;
    }

    return count+1;

}

int readData(string filename, string characters[], int attributes[][3], int arrSize, int splits) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Could not open file." << endl;
        return -1;
    }

    string line;
    int count = 0;
    string arr[4] = {};
    while (getline(fin, line) && count < arrSize) {
        if (split(line, '-', arr, 4) == splits) {
            characters[count] = arr[0];
            for (int i = 1; i < 4; i++) {
                attributes[count][i-1] = stoi(arr[i]);
            }
            count++;
        }
    }
    fin.close();
    return count;

}

int main() {

    string characters[3];
    int attributes[3][3];
    
    // test 1
    assert(readData("../data_files/game_samples.txt", characters, attributes, 3, 4) == 3);

    // test 2
    // expected output: Could not open file.
    assert(readData("../data_files/imaginary_file.txt", characters, attributes, 3, 4) == -1);

    return 0;

}
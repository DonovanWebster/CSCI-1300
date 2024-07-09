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

int readOrders(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Could not open file." << endl;
        return -1;
    }

    string line;
    int numOrders = 0;
    string arr[3] = {};
    while (getline(fin, line)) {
        if (line != "") {
            if (split(line, '-', arr, 3) == 3) {
                numOrders++;
            }
        }
    }
    return numOrders;
}

int main() {

    // test 1
    assert(readOrders("../data_files/bakery_orders.txt") == 4);

    // test 2
    // expected output: Could not open file.
    assert(readOrders("../data_files/imaginary_file.txt") == -1);

    return 0;

}
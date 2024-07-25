#include <iostream>
using namespace std;

// TODO
// Implement print_elements here
void print_elements(string arr[], int arrSize, int idx) {
    if (idx < arrSize) {
        cout << arr[idx] << endl;
        print_elements(arr, arrSize, idx+1);
    }
}

int main() {
    int arrSize;
    cout << "Enter the array size:" << endl;
    cin >> arrSize;
    if (arrSize <= 0) {
        cout << "Not a valid array size" << endl;
        return 0;
    }

    string arr[arrSize] = {};
    cout << "Enter each array element separated by space:" << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cout << "Array elements:" << endl;
    print_elements(arr, arrSize, 0);

    return 0;
}
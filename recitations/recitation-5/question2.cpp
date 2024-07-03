#include <iostream>

using namespace std;

void swap(int myArray[], int index1, int index2) {
    int temp = myArray[index1];
    myArray[index1] = myArray[index2];
    myArray[index2] = temp;
}

void reverseArray(int myArray[], int myArrayLength) {
    for (int i = 0; i < myArrayLength / 2; i++) {
        swap(myArray, i, (myArrayLength - i - 1));
    }
}

int main() {
    // Since we need to decide the size of an array beforehand
    // we have chosen a size which would be larger than any testcase
    
    // Obviously if there were a test case of more than 100 nos
    // This code would break
    // There is nothing special about 100, it was chosen arbitrarily 
    int a[100];
    
    // TODO
    
    // Take in array size
    int n;
    cout << "Please enter the size of the array:" << endl;
    cin >> n;
    
    // Populate the array with user entered integers
    cout << "Please enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Call the reverseArray() function
    reverseArray(a, n);
    
    // Printing out the array in one line is done for you
    // Notice how we avoid printing out an extra space after printing the last element
    cout << "The reversed array is:" << endl;
    for(int i = 0; i < n; i++) {
        if(i < n-1) {
            cout << a[i] << " ";
        }
        else {
            cout << a[i];
        }
    }
}
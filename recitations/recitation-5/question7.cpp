#include<iostream>
using namespace std;
 
void matrixSum(int a[][3], int b[][3], int row) {
    cout << "The sum is:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[2][3], b[2][3];
  
    // TODO  
    // Take input for matrix 1
    cout << "Enter values for matrix 1, one row at a time:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
   
    // Take input for matrix 2
    cout << "Enter values for matrix 2, one row at a time:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }
   
    // Call matrixSum()
    matrixSum(a, b, 2);

    return 0;
}
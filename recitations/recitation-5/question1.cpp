#include <iostream>

using namespace std;

// TODO:
// Define passByValue() here
void passByValue(int x, int y) {
    x += 3;
    y += 2;
}

// TODO: 
// Define passByPointer() here
void passByPointer(int* x, int* y) {
    *x += 3;
    *y += 2;
}

int main(){
    int num1 = 0; 
    int num2 = 0;
    cout<<"Enter two numbers separated by space: "<<endl;
    cin >> num1 >> num2;

    // TODO:
    // Call passByValue() here
    passByValue(num1, num2);

    cout<<"Pass By Value: "<< "num1 = "<<num1<<" num2 = "<<num2<<endl;

    // TODO:
    // Call passByPointer() here
    passByPointer(&num1, &num2);
    
    cout<<"Pass By Pointer: "<< "num1 = "<<num1<<" num2 = "<<num2<<endl;

}
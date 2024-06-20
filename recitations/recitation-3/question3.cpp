#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int sum = 0; 
    while(x >= 10) 
    {
        sum += x;
        x--;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
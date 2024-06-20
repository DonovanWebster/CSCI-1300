#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int sum = 0;
    int i = 0;
    while (i < x) {
        sum -= x;
        i++;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
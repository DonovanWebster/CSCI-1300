#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int sum = -40;
    int i;
    for(i=0; i < x; i++)
    {
        sum += x;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
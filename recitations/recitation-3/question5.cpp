#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 5;
    int sum = 0;
    do 
    {
        sum = x + y;
        cout << "Sum = " << sum << endl;
        x++;
        y++;
    } while (sum <= 20);
    return 0;
}
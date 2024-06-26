#include <iostream>
using namespace std;

double avg(int a, int b);

int main()
{
    cout << avg(8,13) << endl;
    return 0;
}

double avg(int a, int b)
{
    return (a+b) / 2.0;
}

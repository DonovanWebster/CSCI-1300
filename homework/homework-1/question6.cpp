#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int x;
    float sigmoid;

    cout << "Enter a value for x:" << endl;
    cin >> x;

    sigmoid = 1.0 / (1.0 + exp(-x));

    cout << "The sigmoid for x=" << x << " is " << sigmoid << endl;

    return 0;

}
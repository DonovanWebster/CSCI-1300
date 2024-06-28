#include <iostream>

using namespace std;

int main() {

    int num;
    bool isprime = true;

    cout << "Enter a number:" << endl;
    cin >> num;

    if (num <= 1) {
        isprime = false;
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isprime = false;
            }
        }
    }

    if (isprime) {
        cout << "Number is prime" << endl;
    } else {
        cout << "Number is not prime" << endl;
    }
    
    return 0;

}
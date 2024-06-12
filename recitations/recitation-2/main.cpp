#include <iostream>

using namespace std;

int main() {

    int water;
    cout << "How much water did you drink today? (in fl ozs)" << endl;
    cin >> water;

    if (water < 0) {
        cout << "Invalid input" << endl;
        return 1;
    }

    if (water >= 64) {
        cout << "You have hit your goal for the day! Great job getting hydrated!" << endl;
    } else if (water >= 32) {
        cout << "You are doing great, you are half way to your goal! Get that water in! ";
        cout << "You have " << 64 - water << " fl oz left to drink." << endl;
    } else {
        cout << "You are very, very dehydrated! Get that water in! You have " << 64 - water << " fl oz left to drink." << endl;
    }

    return 0;

}
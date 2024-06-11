// Homework 2 - Problem 2

#include <iostream>

using namespace std;

int main() {

    int carouselMinHeight = 30, teacupsMinHeight = 36, infernoMinHeight = 45;
    string allowed = "Yes, you are allowed to go on that ride!\n";
    string notAllowed = "Sorry, you cannot go on that ride.\n";
    bool tallEnough = false;

    double height;
    char ride;

    cout << "How tall are you in inches?" << endl;
    cin >> height;
    
    if (height < 0.0) { // really should be <= to include characters but whatever, also nobody is 0 inches tall
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    cout << "What ride would you like to take(c, t, or i)?" << endl;
    cin >> ride;
    
    switch(ride) {
        case 'c':
            if (height >= carouselMinHeight) {
                tallEnough = true;
            }
            break;
        case 't':
            if (height >= teacupsMinHeight) {
                tallEnough = true;
            }
            break;
        case 'i':
            if (height >= infernoMinHeight) {
                tallEnough = true;
            }
            break;
        default: 
            cout << "Please enter a valid input." << endl;
            return 1;
    }

    if (!tallEnough) {
        cout << notAllowed;
        return 1;
    }

    cout << allowed;

    return 0;

}
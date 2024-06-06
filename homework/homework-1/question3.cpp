// Homework 1 - Problem 3

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double side, height, volume;

    cout << "What is the side length of the base of the carton in inches?" << endl;
    cin >> side;
    cout << "What is the height of the carton in inches?" << endl;
    cin >> height;
    volume = 0.55 * (side * side * height);
    cout << fixed << setprecision(2) << "The carton has a volume of " << volume << " ounces." << endl;

    return 0;

}
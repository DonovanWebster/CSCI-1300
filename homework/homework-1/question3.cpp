#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int sideLength, height;
    float volume;

    cout << "What is the side length of the base of the carton in inches?" << endl;
    cin >> sideLength;
    cout << "What is the height of the carton in inches?" << endl;
    cin >> height;
    volume = 0.55 * (sideLength * sideLength * height);
    cout << fixed << setprecision(2) << "The carton has a volume of " << volume << " ounces." << endl;

    return 0;

}
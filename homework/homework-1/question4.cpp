#include <iostream>

using namespace std;

int main() {
    int breckenSnowRate = 15, vailSnowRate = 11, copperSnowRate = 3;
    int breckenMeltRate = 4, vailMeltRate = 7, copperMeltRate = 2;
    int breckenSnow, vailSnow, copperSnow;
    int days;

    cout << "How many days in the future would you like a prediction for?" << endl;
    cin >> days;

    breckenSnow = 28 + (breckenSnowRate * days) - (breckenMeltRate * days);
    vailSnow = 33 + (vailSnowRate * days) - (vailMeltRate * days);
    copperSnow = 55 + (copperSnowRate * days)- (copperMeltRate * days);

    cout << "Breckenridge will have " << breckenSnow << " inches, Vail will have " << vailSnow << " inches, and Copper Mountain will have " << copperSnow << " inches." << endl;
}
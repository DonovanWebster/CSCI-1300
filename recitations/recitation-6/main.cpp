#include  <iostream>
#include <fstream>

using namespace std;

bool isRed(int y, int stripeHeight) {
    bool firstStripe = y <= stripeHeight;
    bool secondStripe = y > 2 * stripeHeight && y <= 3 * stripeHeight;
    bool thirdStripe = y > 4 * stripeHeight && y <= 5 * stripeHeight;
    bool fourthStripe = y > 6 * stripeHeight && y <= 7 * stripeHeight;
    bool fifthStripe = y > 8 * stripeHeight && y <= 9 * stripeHeight;
    bool sixthStripe = y > 10 * stripeHeight && y <= 11 * stripeHeight;
    bool seventhStripe = y > 12 * stripeHeight;
    return firstStripe || secondStripe || thirdStripe || fourthStripe || fifthStripe || sixthStripe || seventhStripe;
}

int main() {

    // 13 stripes in the flag
    int stripes = 13;
    int h_stripe;

    cout << "Enter height of each stripe in pixels (integer):" << endl;
    cin >> h_stripe;

    int h = stripes * h_stripe;  // Assume each stripe would be h_stripe pixels in height  
    int w = h * 1.9;  // Actual flag proportions

    // Union dimensions (round to nearest int) the dimension of the blue section
    int union_w = 0.4 * w; 
    
    //TODO: Write the PGM file header
    cout << "P3" << endl;
    cout << w << " " << h << endl;
    cout << 255 << endl;

    string WHITE = "255 255 255";
    string RED = "179 25 66";
    string BLUE = "10 49 97";

    // TODO: Write a nested for loop logic to print the flag
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if (j < union_w && i <= union_w) {
                cout << BLUE << " ";
            } else if (isRed(i, h_stripe)) {
                cout << RED << " ";
            } else {
                cout << WHITE << " ";
            }
            
        }
        cout << endl;
    }

    return 0;
}
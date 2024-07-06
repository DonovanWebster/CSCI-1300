#include <fstream>
#include <cmath>

using namespace std;

void printFileHeader(ofstream &file, int width, int height) {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInCircle(int x, int y, double radius) {
    return sqrt(pow(x, 2) + pow(y, 2)) < radius;
}

int main() {

    string NAVY_BLUE = "0 0 128";
    string SAFFRON = "255 153 51";
    string WHITE = "255 255 255";
    string INDIA_GREEN = "19 136 8";
    
    int width = 450;
    int height = 300;

    ofstream outFile("../problem-1e/problem1e.ppm");
    printFileHeader(outFile, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (i < 100) {
                outFile << SAFFRON << " ";
            } else if (i < 200) {
                if (isInCircle(x, y, 45)) {
                    outFile << NAVY_BLUE << " ";
                } else {
                    outFile << WHITE << " ";
                }
            } else {
                outFile << INDIA_GREEN << " ";
            }

        }
        outFile << endl;
    }

    return 0;

}
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

    string JAPAN_RED = "188 0 45";
    string WHITE = "255 255 255";
    
    int width = 600;
    int height = 400;

    ofstream outFile("../problem-1/problem-1d/problem1d.ppm");
    printFileHeader(outFile, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (isInCircle(x, y, (0.3 * height))) {
                outFile << JAPAN_RED << " ";
            } else {
                outFile << WHITE << " ";
            }
        }
        outFile << endl;
    }

    return 0;

}
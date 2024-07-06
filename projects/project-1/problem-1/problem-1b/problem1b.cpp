#include <fstream>
#include <cmath>

using namespace std;

void printFileHeader(ofstream &file, int width, int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInCircle(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2)) < 30;
}

int main() {

    int width = 100;
    int height = 100;

    ofstream outFile("../problem-1/problem-1b/problem1b.pgm");
    printFileHeader(outFile, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (isInCircle(x, y)) {
                outFile << 255 << " ";
            } else {
                outFile << 0 << " ";
            }
        }
        outFile << endl;
    }

    return 0;

}
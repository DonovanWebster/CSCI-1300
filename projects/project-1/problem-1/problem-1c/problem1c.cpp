#include <fstream>
#include <cmath>

using namespace std;

void printFileHeader(ofstream &file, int width, int height) {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInCircle(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2)) < 30;
}

int main() {

    string RED = "255 0 0";
    string YELLOW = "255 255 0";
    
    int width = 100;
    int height = 100;

    ofstream outFile("../problem-1/problem-1c/problem1c.ppm");
    printFileHeader(outFile, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (isInCircle(x, y)) {
                outFile << YELLOW << " ";
            } else {
                outFile << RED << " ";
            }
        }
        outFile << endl;
    }

    return 0;

}
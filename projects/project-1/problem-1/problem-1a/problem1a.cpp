#include <fstream>

using namespace std;

void printFileHeader(ofstream &file, int width, int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

int main() {

    int width = 100;
    int height = 100;
    int sideLength = 50; // side length of the square in pixels

    ofstream outFile("../problem-1a/problem1a.pgm");
    printFileHeader(outFile, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if ((x > (-sideLength/2)) && (x < (sideLength/2)) && (y > (-sideLength/2)) && (y < (sideLength/2))) {
                outFile << 0 << " ";
            } else {
                outFile << 255 << " ";
            }
        }
        outFile << endl;
    }
    outFile.close();

    return 0;

}
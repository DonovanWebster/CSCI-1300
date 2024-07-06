#include <fstream>
#include <cmath>

using namespace std;

void print(ofstream &file, int arr[][100], const int width, const int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            file << (to_string(arr[j][i]) + " ");
        }
        file << endl;
    }
}

void fillRectangle(int arr[][100], const int color, const int width, const int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arr[j][i] = color;
        }
    }
}

void fillCircle(int arr[][100], const int color, double radius, const int width, const int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (sqrt(pow(x, 2) + pow(y, 2)) < radius) {
                arr[j][i] = color;
            }

        }
    }
}

int main() {

    int width = 100;
    int height = 100;
    int fileArr[100][100];

    fillRectangle(fileArr, 0, width, height);
    fillCircle(fileArr, 255, 30, width, height);

    ofstream outFile("../problem-1b/problem1b.pgm");
    print(outFile, fileArr, width, height);
    outFile.close();

    return 0;

}
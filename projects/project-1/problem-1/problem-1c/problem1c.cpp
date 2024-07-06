#include <fstream>
#include <cmath>

using namespace std;

void print(ofstream &file, int arr[][100][3], const int width, const int height) {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            string line = "";
            for (int k = 0; k < 3; k++) {
                line += (to_string(arr[j][i][k]) + " ");
            }
            file << line;
        }
        file << endl;
    }
}

void fillRectangle(int arr[][100][3], const int color[], const int width, const int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                arr[j][i][k] = color[k];
            }
        }
    }
}

void fillCircle(int arr[][100][3], const int color[], double radius, const int width, const int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);

            if (sqrt(pow(x, 2) + pow(y, 2)) < radius) {
                for (int k = 0; k < 3; k++) {
                    arr[j][i][k] = color[k];
                }
            }

        }
    }
}

int main() {

    int RED[] = {255, 0, 0};
    int YELLOW[] = {255, 255, 0};
    
    int width = 100;
    int height = 100;
    int fileArr[100][100][3];

    fillRectangle(fileArr, RED, width, height);
    fillCircle(fileArr, YELLOW, 30, width, height);

    ofstream outFile("../problem-1c/problem1c.ppm");
    print(outFile, fileArr, width, height);
    outFile.close();

    return 0;

}
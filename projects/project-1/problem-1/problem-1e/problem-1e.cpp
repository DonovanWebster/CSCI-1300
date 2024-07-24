#include <fstream>
#include <cmath>

using namespace std;

void print(ofstream &file, int arr[][300][3], const int width, const int height) {
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

void fillRectangles(int arr[][300][3], const int colors[][3], const int width, const int height, const int rectHeight) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int firstIndex;
            if (i < rectHeight) { // first rectangle
                firstIndex = 0;
            } else if (i < 2 * rectHeight) { // second rectangle
                firstIndex = 1;
            } else { // third rectangle
                firstIndex = 2;
            }
            for (int k = 0; k < 3; k++) {
                arr[j][i][k] = colors[firstIndex][k];
            }
        }
    }
}

void fillCircle(int arr[][300][3], const int color[], double radius, const int width, const int height) {
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

    int NAVY_BLUE[] = {0, 0, 128};
    int COLORS[3][3] = {
        {255, 153, 52}, // saffron
        {255, 255, 255}, // white
        {19, 136, 8} // india green
    };
    int width = 450;
    int height = 300;
    int rectHeight = 100; // height of a colored rectangle
    int fileArr[450][300][3];

    fillRectangles(fileArr, COLORS, width, height, rectHeight);
    fillCircle(fileArr, NAVY_BLUE, 45, width, height);

    ofstream outFile("../problem-1e/problem1e.ppm");
    print(outFile, fileArr, width, height);
    outFile.close();

    return 0;

}
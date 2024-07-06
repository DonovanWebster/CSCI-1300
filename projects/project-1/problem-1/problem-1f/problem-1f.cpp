#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

void printFileHeader(ofstream &file, const int width, const int height) {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

void print(ofstream &file, int arr[][300][3], const int width, const int height) {
    printFileHeader(file, width, height);
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

void fillRectangle(int arr[][300][3], const int color[], const int width, const int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                arr[j][i][k] = color[k];
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

void toPolar(int x, int y, double &r, double &theta) {
    const double pi = 3.1415926535;
    r = sqrt(pow(x, 2) + pow(y, 2));
    if (x == 0) {
        if (y > 0) {
            theta = (pi / 2.0);
        } else if (y < 0) {
            theta = ((3.0 * pi) / 2.0);
        } else {
            theta = 0;
        }
        return;
    }
    theta = atan(double(y)/double(x));
    if (x < 0) {
        theta += pi;
    } else if (y < 0) {
        theta += (2.0 * pi);
    }
}

double radians(double deg) {
    const double pi = 3.1415926535;
    return ((deg * pi) / 180.0);
}

bool isInSpoke(double r, double inner, double outer, double theta, double deg, double dist) {
    double start;
    if (deg == radians(20)) {
        start = radians(20);
    } else if (deg == radians(30)) {
        start = radians(15);
    } else {
        start = radians(27);
    }
    bool firstSpoke = (theta >= deg) && (theta <= (start + deg));
    if (deg == radians(20)) {
        start = 2 * dist;
    } else {
        start += (deg + dist);
    }
    bool secondSpoke = (theta >= start) && (theta <= (start + deg));
    start += (deg + dist);
    bool thirdSpoke = (theta >= start) && (theta <= (start + deg));
    start += (deg + dist);
    bool fourthSpoke = (theta >= start) && (theta <= (start + deg));
    start += (deg + dist);
    bool fifthSpoke = (theta >= start) && (theta <= (start + deg));
    start += (deg + dist);
    bool sixthSpoke = (theta >= start) && (theta <= (start + deg));

    bool inRange = (r >= inner) && (r <= outer);

    return (firstSpoke || secondSpoke || thirdSpoke || fourthSpoke || fifthSpoke || sixthSpoke) && inRange;
}

void fillSpokes(int arr[][300][3], const int width, const int height) {
    const int WHITE[] = {255, 255, 255};
    const int BLACK[] = {0, 0, 0};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2);
            int y = i - (height/2);
            
            double r, theta;
            toPolar(x, y, r, theta);
            // inner spokes
            if (isInSpoke(r, 34, 68, theta, radians(20), radians(40))) {
                for (int k = 0; k < 3; k++) {
                    arr[j][i][k] = WHITE[k];
                }
            }
            // middle and outer spokes
            if (isInSpoke(r, 84, 93, theta, radians(30), radians(30)) || isInSpoke(r, 93, 102, theta, radians(6), radians(54))) {
                for (int k = 0; k < 3; k++) {
                    arr[j][i][k] = BLACK[k];
                }
            }
        }
    }
}

int main() {

    // color taken by using a color picker
    const int EMPIRE_RED[] = {212, 0, 0};
    const int WHITE[] = {255, 255, 255};
    const int BLACK[] = {0, 0, 0};
    
    const int width = 500;
    const int height = 300;
    int arr[500][300][3];

    fillRectangle(arr, EMPIRE_RED, width, height);
    // all values for radii were found by examining the reference image in krita
    fillCircle(arr, BLACK, 111, width, height);
    fillCircle(arr, WHITE, 102, width, height);
    fillCircle(arr, BLACK, 84, width, height);
    fillCircle(arr, WHITE, 34, width, height);
    fillSpokes(arr, width, height);

    ofstream outFile("../problem-1f/problem1f.ppm");

    print(outFile, arr, width, height);

    outFile.close();

    return 0;

}
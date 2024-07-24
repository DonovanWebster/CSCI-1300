#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

void printHeader(ofstream &file, const int width, const int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInSet(complex<double> c, double radius) {
    complex<double> z = 0; // current number in the sequence
    double abs_val = 0; // aboslute value of z
    int i = 0; // a coutner for the number of iterations
    do {
        abs_val = sqrt(pow(real(z), 2) + pow(imag(z), 2));
        z = pow(z, 2) + c;
        i++;
    } while (abs_val <= radius && i <= 255);
    if (abs_val <= radius) {
        return true; // reached max iterations but still in the set
    }
    return false; // not in the set
}

int main() {

    int height = 500, width = 500;
    double zoom = 2.0, radius = 2.0;
    ofstream fout("../problem-3a/problem-3a.pgm");
    printHeader(fout, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double y = (i - height/2.0) / (height/2.0);
            double x = (j - width/2.0) / (width/2.0);
            complex<double> c = zoom * complex<double>(x, y);

            if (isInSet(c, radius)) {
                fout << "0 ";
            } else {
                fout << "255 ";
            }

        }
        fout << endl;
    }

}
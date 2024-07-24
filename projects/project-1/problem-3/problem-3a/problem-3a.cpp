#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

void printHeader(ofstream &file, const int width, const int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInSet(complex<double> c, double r) {
    complex<double> z = 0;
    double abs_val = 0;
    int i = 0;
    do {
        abs_val = sqrt(pow(real(z), 2) + pow(imag(z), 2));
        z = pow(z, 2) + c;
        i++;
    } while (abs_val <= r && i <= 1000);
    if (abs_val <= r) {
        return true;
    }
    return false;
}

int main() {

    int h = 500, w = 500;
    double zoom = 2.0, radius = 2.0;
    ofstream fout("../problem-3a/problem-3a.pgm");
    printHeader(fout, w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            double y = (i - h/2.0) / (h/2.0);
            double x = (j - w/2.0) / (w/2.0);
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
#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

void printHeader(ofstream &file, const int width, const int height) {
    file << "P2" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInSet(complex<double> c, double r, int &itr, const int MAX_ITR) {
    complex<double> z = 0; // current number in the sequence
    double abs_val = 0; // aboslute value of z
    do {
        abs_val = sqrt(pow(real(z), 2) + pow(imag(z), 2));
        z = pow(z, 2) + c;
        itr++;
    } while (abs_val <= r && itr <= MAX_ITR);
    if (abs_val <= r) {
        return true; // reached max iterations but still in the set
    }
    return false; // not in the set
}

int main() {

    int h = 500, w = 500;
    double zoom = 2.0, radius = 2.0;
    int itr = 0; // counter for the number of iterations of the sequence
    const int MAX_ITR = 255;
    ofstream fout("../problem-3b/problem-3b.pgm");
    printHeader(fout, w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            double y = (i - h/2.0) / (h/2.0);
            double x = (j - w/2.0) / (w/2.0);
            complex<double> c = zoom * complex<double>(x, y);

            if (isInSet(c, radius, itr, MAX_ITR)) {
                fout << "0 ";
            } else {
                fout << itr << " ";
            }
            itr = 0;

        }
        fout << endl;
    }

}
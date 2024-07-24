#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

void printHeader(ofstream &file, const int width, const int height) {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

bool isInSet(complex<double> c, double r, int &itr, const int MAX_ITR) {
    complex<double> z = 0;
    double abs_val = 0;
    do {
        abs_val = sqrt(pow(real(z), 2) + pow(imag(z), 2));
        z = pow(z, 2) + c;
        itr++;
    } while (abs_val <= r && itr <= MAX_ITR);
    if (abs_val <= r) {
        return true;
    }
    return false;
}

double radians(double deg) {
    const double pi = 3.1415926535;
    return ((deg * pi) / 180.0);
}

bool isInDiagSets(double x, double y, double zoom, double radius, int itrs[8], const int MAX_ITR) {
    complex<double> right  = complex<double>(-zoom, 0) + zoom * complex<double>( x, y) * complex<double>(cos(radians(-45)), sin(radians(-45)));
    complex<double> left   = complex<double>(-zoom, 0) + zoom * complex<double>(-x, y) * complex<double>(cos(radians(45)), sin(radians(45)));
    complex<double> bottom = complex<double>(-zoom, 0) + zoom * complex<double>( y, x) * complex<double>(cos(radians(45)), sin(radians(45)));
    complex<double> top    = complex<double>(-zoom, 0) + zoom * complex<double>(-y, x) * complex<double>(cos(radians(-45)), sin(radians(-45)));
    bool isInRight = isInSet(right, radius, itrs[4], MAX_ITR);
    bool isInLeft = isInSet(left, radius, itrs[5], MAX_ITR);
    bool isInBottom = isInSet(bottom, radius, itrs[6], MAX_ITR);
    bool isInTop = isInSet(top, radius, itrs[7], MAX_ITR);
    return isInRight || isInLeft || isInBottom || isInTop;
}

bool isInHorzSets(double x, double y, double zoom, double radius, int itrs[8], const int MAX_ITR) {
    complex<double> right  = complex<double>(-zoom, 0) + zoom * complex<double>( x, y);
    complex<double> left   = complex<double>(-zoom, 0) + zoom * complex<double>(-x, y);
    complex<double> bottom = complex<double>(-zoom, 0) + zoom * complex<double>( y, x);
    complex<double> top    = complex<double>(-zoom, 0) + zoom * complex<double>(-y, x);
    bool isInRight = isInSet(right, radius, itrs[0], MAX_ITR);
    bool isInLeft = isInSet(left, radius, itrs[1], MAX_ITR);
    bool isInBottom = isInSet(bottom, radius, itrs[2], MAX_ITR);
    bool isInTop = isInSet(top, radius, itrs[3], MAX_ITR);
    return isInRight || isInLeft || isInBottom || isInTop;
}

int isInSets(double x, double y, double zoom, double radius, int itrs[8], const int MAX_ITR) {
    bool horz = isInHorzSets(x, y, zoom, radius, itrs, MAX_ITR);
    bool diag = isInDiagSets(x, y, 2 * zoom, radius, itrs, MAX_ITR);
    if (horz) {
        return 0;
    }
    if (diag) {
        return 1;
    }
    return -1;
}

int main() {

    int h = 500, w = 500;
    double zoom = 1.5, radius = 2.0;
    int itrs[8] = {0};
    // int itr = 0;
    const int MAX_ITR = 255;
    ofstream fout("../problem-3d/problem-3d.ppm");
    printHeader(fout, w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            double y = (i - h/2.0) / (h/2.0);
            double x = (j - w/2.0) / (w/2.0);

            int result = isInSets(x, y, zoom, radius, itrs, MAX_ITR);
            if (result == 0) {
                fout << "0 0 0 ";
            } else if (result == 1) {
                fout << "255 255 255 ";
            } else {
                int purp_val = 0, red_val = 0;
                for (int k = 0; k < 8; k++) {
                    if (k < 4) {
                        purp_val += itrs[k];
                    } else {
                        red_val += itrs[k];
                    }
                }
                purp_val /= 4;
                red_val /= 4;
                string r = to_string(((purp_val * 4)+(red_val*16))/2) + " ";
                string g = to_string(((purp_val)+(red_val))/2) + " ";
                string b = to_string(((purp_val * 8)+(red_val))/2) + " ";
                fout << r << g << b;
            }
            for (int l = 0; l < 8; l++) {
                itrs[l] = 0;
            }
            // itr = 0;
        }
        fout << endl;
    }

}
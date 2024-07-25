#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double calcRect(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Could not open file" << endl;
        return -1;
    }

    double sum = 0;

    string line;
    while (getline(fin, line)) {
        if (line.empty()) {
            continue;
        }
        int idx = line.find(" ", 11);
        double length = stod(line.substr(11, idx));
        double breadth = stod(line.substr(idx+1, line.length()));
        if (length > 0 && breadth > 0) {
            sum += (length * breadth);
        }
    }

    fin.close();

    if (sum == 0) {
        cout << "Need a positive value to calculate total area" << endl;
        return -1;
    }

    return sum;
}

int main() {

    cout << calcRect("../question2/example.txt") << endl;

    return 0;

}
#include <iostream>

using namespace std;

double fertilize(double stock, double amount) {
    if (stock - amount < 0) {
        cout << "Error: not enough fertilizer!" << endl;
        return stock;
    }
    return stock - amount;
}

double restock(double stock, double amount) {
    return stock + amount;
}
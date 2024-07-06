// Homework 4 - Problem 1 - arrayStats

#include <iostream>
#include <cassert>

using namespace std;

double min(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double sum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double average(double arr[], int size) {
    return sum(arr, size) / size;
}

bool doubles_equal(double a, double b, const double epsilon = 1e-2) {
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

int main() {

    // test 1
    double arr1[] = {1.24, 5.68, 3.456};
    int len1 = 3;
    assert(doubles_equal(min(arr1, len1), 1.24)); // min test 1
    assert(doubles_equal(sum(arr1, len1), 10.376)); // sum test 1
    assert(doubles_equal(average(arr1, len1), 3.4587)); // average test 1

    // test 2
    double arr2[] = {0};
    int len2 = 1;
    assert(doubles_equal(min(arr2, len2), 0)); // min test 2
    assert(doubles_equal(sum(arr2, len2), 0)); // sum test 2
    assert(doubles_equal(average(arr2, len2), 0)); // average test 2

    return 0;

}
#include <fstream>
#include <iostream>

using namespace std;

// Use a power of 3 as width to avoid rounding issues, order 8 max
const int WIDTH = 50;  // 3^8

void display(char a[][WIDTH], int height, int order, ostream* out) {
    int HEIGHT = height*(order+1);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            *out << a[i][j] << " ";
        }
        *out << endl;
    }
}

void paint_empty(char a[][WIDTH], int start_y, int height, int start_x, int size, int order) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < WIDTH; j++) {
            a[i][j] = '0';
        }
    }
    for (int i = start_y; i < start_y + height; i++) {
        for (int j = start_x; j < start_x + size; j++) {
            a[i][j] = '1';
        }
    }
}

void cantor(char a[][WIDTH], int start_y, int height, int start_x, int size, int order) {

}

int main() {

    // int height = 10;
    // char arr[40][WIDTH] = {0};
    // int order = 3;

    // cantor(arr, 0, height, 0, WIDTH, order);

    // print array
    // for(int i = 0; i < (height * (order + 1)); i++) {
    //     bool printed = false;
    //     for(int j = 0; j < WIDTH; j++) {
    //         if(arr[i][j] == '1'|| arr[i][j] == '0') {
    //             cout << arr[i][j] << " ";
    //             printed = true;
    //         }
    //     }
    //     if(printed){
    //         cout << endl;
    //     }

    // }

    int height = 10;

    char arr[10 * 20][WIDTH] = {0};

    int order = 6;

    for(int i = 0; i < height * 20; i++) {
        for(int j = 0; j < WIDTH; j++) {
            arr[i][j] = '1';
        }
    }

    // paint_empty(arr, 50, 50, 50, 50, order);

    // for(int i = 0; i < height * 20; i++) {
    //     bool paint = false;
    //     for(int j = 0; j < WIDTH; j++) {
    //         if(arr[i][j] == '0'){
    //             cout << arr[i][j];
    //             paint = true;
    //         }
    //     }
    //     if(paint == true){
    //         cout << endl;
    //     }
    // }

    ofstream fout("out.pgm");

    fout << "P2" << endl;
    fout << WIDTH << " " << height*(order+1) << endl;
    fout << 255 << endl; // Max pixel intensity

    for (int i = 0; i < height*20; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fout << arr[i][j] << " ";
        }
        fout << endl;
    }

}
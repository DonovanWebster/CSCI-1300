#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

class Block {
    public:
        int x;
        int y;
        int width;
        vector<Block> blocks;

    Block() {
        x = 0;
        y = 0;
        width = 0;
        blocks = createBlocks();
    }

    Block(int x, int y, int width) {
        this->x = x;
        this->y = y;
        this->width = width;
        blocks = createBlocks();
    }

    private:

        vector<Block> createBlocks() {
            vector<Block> vec = {};
            if (width > 1) {
                for (int i = 0; i < (3 * width); i += width) {
                    for (int j = 0; j < (3 * width); j += width) {
                        int pos[] = {x-((2*width)/3)+i, y-((2*width)/3)+j};
                        if (!(pos[0] == x+(width/3) && pos[1] == y+(width/3))) {
                            vec.push_back(Block(pos[0], pos[1], width/3));
                        }
                    }
                }
            }
            return vec;
        }
};

bool isBlockPos(Block block, int x, int y) {
    
    // bool isInX = block.x <= x && x <= block.x + (block.width - 1);
    // bool isInY = block.y <= y && y <= block.y + (block.width - 1);
    // if (isInX && isInY) {
    //     return true;
    // }

    //if (block.width > 1) {
        bool top = y < block.y;
        bool bottom = y > block.y + (block.width - 1);

        bool left = x < block.x;
        bool right = x > block.x + (block.width - 1);

        int idx;

        if (top) {
            if (left) {
                idx = 0;
            } else if (right) {
                idx = 5;
            } else {
                idx = 3;
            }
        } else if (bottom) {
            if (left) {
                idx = 2;
            } else if (right) {
                idx = 7;
            } else {
                idx = 4;
            }
        } else {
            if (left) {
                idx = 1;
            } else if (right) {
                idx = 6;
            } else {
                return true;
            }
        }

        if (block.width > 1) {
        return isBlockPos(block.blocks[idx], x, y);
        }
        return false;
    //}

    //return false;

    // bool isInX = block.x <= x && x <= block.x + (block.width - 1);
    // bool isInY = block.y <= y && y <= block.y + (block.width - 1);
    // if (isInX && isInY) {
    //     return true;
    // }
    // if (block.width > 1) {
    //     for (int i = 0; i < 8; i++) {
    //         if (isBlockPos(block.blocks[i], x, y)) {
    //             return true;
    //         };
    //     }
    // }
    // return false;
}

void printBlocks(ofstream &file, Block block, const int imgWidth) {
    file << "P2" << endl;
    file << imgWidth << " " << imgWidth << endl;
    file << 255 << endl;

    for (int i = 0; i < imgWidth; i++) {
        for (int j = 0; j < imgWidth; j++) {
            if (isBlockPos(block, i, j)) {
                file << 0 << " ";
            } else {
                file << 255 << " ";
            }
        }
        file << endl;
    }
}

// void print(ofstream &file, int arr[][243], const int width) {
//     file << "P2" << endl;
//     file << width << " " << width << endl;
//     file << 255 << endl;

//     for (int i = 0; i < width; i++) {
//         for (int j = 0; j < width; j++) {
//             file << (to_string(arr[j][i]) + " ");
//         }
//         file << endl;
//     }
// }

// void fill(int arr[][243], const int color, const int width) {
//     for (int i = 0; i < width; i++) {
//         for (int j = 0; j < width; j++) {
//             arr[i][j] = color;
//         }
//     }
// }

// void recursiveFill(int arr[][243], const int color, const int startPos[], const int length, const int width) {
//     for (int i = startPos[1]; i < (startPos[1] + length); i++) {
//         for (int j = startPos[0]; j < (startPos[0] + length); j++) {
//             arr[j][i] = color;
//         }
//     }

//     if (length <= 1) {
//         return;
//     }

//     for (int x = 0; x < width; x += length) {
//         for (int y = 0; y < width; y += length) {
//             int newStart[] = {startPos[0]-((2*length)/3)+x, startPos[1]-((2*length)/3)+y};
//             recursiveFill(arr, color, newStart, length/3, width/3);
//         }
//     }

// }

int main(int argc, char* argv[]) {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    // const int WHITE = 255;
    // const int BLACK = 0;

    int width = stoi(argv[1]);
    // int width = 9;
    // int fileArr[243][243];

    // int startPos[] = {width/3, width/3};
    // fill(fileArr, WHITE, width);
    // recursiveFill(fileArr, BLACK, startPos, width/3, width);

    ofstream outFile("../problem-2a/problem2a.pgm");
    // print(outFile, fileArr, width);
    Block block = Block(width/3, width/3, width/3);
    printBlocks(outFile, block, width);
    outFile.close();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference (sec) = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0  <<std::endl;

    return 0;

}
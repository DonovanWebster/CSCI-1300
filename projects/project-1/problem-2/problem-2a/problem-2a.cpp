#include <fstream>
#include <vector>
#include <iostream>

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
    bool isInX = block.x <= x && x <= block.x + (block.width - 1);
    bool isInY = block.y <= y && y <= block.y + (block.width - 1);
    if (isInX && isInY) {
        return true;
    }
    if (block.width > 1) {
        for (int i = 0; i < 8; i++) {
            if (isBlockPos(block.blocks[i], x, y)) {
                return true;
            };
        }
    }
    return false;
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

    // const int WHITE = 255;
    // const int BLACK = 0;

    // int width = stoi(argv[1]);
    int width = 2187;
    // int fileArr[243][243];

    // int startPos[] = {width/3, width/3};
    // fill(fileArr, WHITE, width);
    // recursiveFill(fileArr, BLACK, startPos, width/3, width);

    ofstream outFile("../problem-2a/problem2a.pgm");
    // print(outFile, fileArr, width);
    printBlocks(outFile, Block(width/3, width/3, width/3), width);
    outFile.close();

    return 0;

}
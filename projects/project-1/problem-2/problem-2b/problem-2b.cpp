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

}

string getFillColor(int x, int y, const int imgWidth) {
    string MAGENTA = "255 0 255";
    string CYAN = "0 255 255";
    string ORANGE = "255 165 0";
    string BLUE = "0 0 255";
    string MINT = "152 251 152";
    string YELLOW = "255 255 0";
    string GREEN = "0 255 0";
    string RED = "255 0 0";
    int width = imgWidth / 3;

    bool top = y < width;
    bool bottom = y > (2 * width) - 1;

    bool left = x < width;
    bool right = x > (2 * width) - 1;

    if (top) {
        if (left) {
            return MAGENTA;
        } else if (right) {
            return ORANGE;
        } else {
            return CYAN;
        }
    } else if (bottom) {
        if (left) {
            return YELLOW;
        } else if (right) {
            return RED;
        } else {
            return GREEN;
        }
    } else {
        if (left) {
            return BLUE;
        } else if (right) {
            return MINT;
        } else {
            return 0;
        }
    }

    return 0;
}

void printBlocks(ofstream &file, Block block, const int imgWidth) {
    file << "P3" << endl;
    file << imgWidth << " " << imgWidth << endl;
    file << 255 << endl;

    for (int i = 0; i < imgWidth; i++) {
        for (int j = 0; j < imgWidth; j++) {
            if (isBlockPos(block, i, j)) {
                file << "0 0 0 ";
            } else {
                file << getFillColor(i, j, imgWidth) << " ";
            }
        }
        file << endl;
    }
}

// this takes exponentially longer to run the larger the image gets, approximate times below:
// width = 81, 0.7 seconds
// width = 243, 46 seconds
// widht = 729, 57 minutes
// this statement will be removed if I have time to fix this
int main(int argc, char* argv[]) {

    int width = stoi(argv[1]);

    ofstream outFile("../problem-2b/problem2b.ppm");
    Block block = Block(width/3, width/3, width/3);
    printBlocks(outFile, block, width);
    outFile.close();

    return 0;

}
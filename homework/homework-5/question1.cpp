#include <iostream>
#include <fstream>

using namespace std;

void tvStreamStats(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Could not open file." << endl;
        return;
    }

    string line, mostStreamedShow, leastStreamedShow;
    int lineCount = 0, mostStreams, leastStreams;
    while (getline(fin, line)) {
        int idx = line.find('-');
        if (lineCount > 0) {
            int streams = stoi(line.substr(idx+1));
            if (streams > mostStreams) {
                mostStreamedShow = line.substr(0, idx);
                mostStreams = streams;
            }
            if (streams < leastStreams) {
                leastStreamedShow = line.substr(0, idx);
                leastStreams = streams;
            }
        } else {
            mostStreamedShow = line.substr(0, idx);
            mostStreams = stoi(line.substr(idx+1));
            leastStreamedShow = line.substr(0, idx);
            leastStreams = stoi(line.substr(idx+1));
        }
        lineCount++;
    }

    fin.close();

    cout << "Number of lines read: " << lineCount << endl;
    cout << "Most streamed show: " << mostStreamedShow << " with " << mostStreams << " streams." << endl;
    cout << "Least streamed show: " << leastStreamedShow << " with " << leastStreams << " streams." << endl;
}

int main() {

    // test 1 for tvStreamStats
    // expected output:
    // Number of lines read: 4
    // Most streamed show: The Office with 887000 streams.
    // Least streamed show: Seinfeld with 675000 streams.
    tvStreamStats("../data_files/show_list.txt");

    // test 2 for tvStreamStats
    // expected output:
    // Could not open file.
    tvStreamStats("../data_files/imaginary_file.txt");

    return 0;

}
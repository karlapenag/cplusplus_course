// Word frequencies -- using map
// Fred Swartz 2001-12-11
// Modified by M. El-Ramly 2012-7-7

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> freq; // map of words and their frequencies
    string word;           // input buffer for words.
    string filename;       // filename to read from
    ifstream infile;       // file handler

    //--- Read filename from user
    cout << "Please enter file name: ";
    cin >> filename;

    //--- Open input file and if failed, return
    infile.open(filename.c_str());
    if (infile.fail()) return -1;

    //--- Read words/tokens from input file
    while (infile >> word) {
        if (infile.fail()) break;
        freq[word]++;
    }

    //--- Write the count and the word.
    map<string, int>::const_iterator iter;
    for (iter=freq.begin(); iter != freq.end(); ++iter) {
        cout << iter->second << " " << iter->first << endl;
    }

    return 0;
}//end main


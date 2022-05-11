// Word frequencies -- using map
// Fred Swartz 2001-12-11

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> freq; // map of words and their frequencies
    string word;           // input buffer for words.

    //--- Read words/tokens from input stream
    while (cin >> word) {
        if (word == "Q") break;
        freq[word]++;
    }

    //--- Write the count and the word.
    map<string, int>::const_iterator iter;
    for (iter=freq.begin(); iter != freq.end(); ++iter) {
        cout << iter->second << " " << iter->first << endl;
    }

    return 0;
}//end main


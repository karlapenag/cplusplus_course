// Word frequencies -- using map -- another version
// Mohammad El-Ramly 2012-7-7

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    //--- Creat a map and an iterator over it
    map<string, int> wordFreq;
    map<string, int>::iterator it;

    //--- Recieve words from the user until he enters "Q" or "q"
    string nextWord;
    cout << "Please enter your text to count yoru words' frequency (Q to end): \n\n";
    cin >> nextWord;
    while (nextWord != "Q" && nextWord != "q"){
         wordFreq [nextWord]++;
         cin >> nextWord;
    }

    //--- Print words in order. Notice the dereferencing of the iterator
    for(it = wordFreq.begin(); it != wordFreq.end(); it++)
         cout << (*it).first << "  " << (*it).second << "\n";

    return 0;
}

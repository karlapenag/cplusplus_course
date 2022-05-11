//
// Created by Karla Angélica Peña Guerra on 3/16/22.
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("text.txt");
    outfile <<  "Hello world" << endl;
    outfile.close();
    ifstream infile("text.txt");
    string text;
    cin >> text;
    infile >> text;
    infile.close();
    return 0;
}

//
// Created by Karla Angélica Peña Guerra on 3/25/22.
//
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    ifstream infile("input.txt");
    int fileSize = count(std::istreambuf_iterator<char>(infile),
                         std::istreambuf_iterator<char>(), '\n');
    cout<<"this is file size: "<< fileSize << endl;
    string text;
    string file_contents;
    int number_of_pointers;
    ifstream filein("input.txt");
    if (filein.fail()) {
        cout << "Input text file does not exist" << endl;
    } else {
        getline(filein, text);
        number_of_pointers = stoi(text);
        cout <<"this is number of pointers : "<< number_of_pointers << endl;
        // filein.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        char ID;
        int counter=0;
        while (!filein.eof()) {

            filein >> ID;
            if (ID=='a'){

                cout<<"hola"<<endl;
                counter+=1;
                cout<<counter<<endl;
            }
        }
    }
    infile.close();
}

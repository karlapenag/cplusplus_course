//
// Created by Karla Angélica Peña Guerra on 3/26/22.
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
    string text2;
    string dsd;
    int number_of_pointers;
    int alloc_size;
    ifstream filein("input.txt");
    if (filein.fail()) {
        cout << "Input text file does not exist" << endl;
    } else {
        getline(filein, text);
        number_of_pointers = stoi(text);
        cout <<"this is number of pointers : "<< number_of_pointers << endl;
        // filein.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        while (!filein.eof()) {
            getline(filein, text);
            stringstream X(text);
            cout<<"this is text: "<<text;
            while (getline(X, text2, ' ')) {
                /* X represents to read the string from stringstream, T use for store the token string and,
                 ' ' whitespace represents to split the string where whitespace is found. */
                //cout << text2 << endl; // print split string
                dsd+=text2;
            }
            cout<<dsd<<endl;
            dsd="";
            /*if (text[0] == 'a'){
                char ID = text[1];
                for (int i=2; i<text.size();i++){
                    alloc_size+=text[i];
                }
                cout<<"ID: "<<ID<<endl;
                cout<<"Alloc size : "<<alloc_size<<endl;
            }
            else if (text[0] == 'd'){

            }*/
        }
    }
    infile.close();

//
// Created by Karla Angélica Peña Guerra on 3/25/22.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;
int main() {
    ifstream infile("input.txt");
    int fileSize = count(std::istreambuf_iterator<char>(infile),
                         std::istreambuf_iterator<char>(), '\n');
    cout<<"this is file size: "<< fileSize << endl;
    string text;
    int number_of_pointers;
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
            string temp="";
            string word = "";
            int num=0;
            string action="";
            string index="";
            action=text[0];
            cout<<"this is action : "<<action<<endl;
            text.erase(0,1);
            int counter=0;
            string size="";
            for (auto x:text){
                if (isspace(x)==0){
                    break;
                }
                else {counter+=1;}
            }
            text.erase(0,counter);
            counter=0;
            for (auto x:text){
                if (isspace(x)==0){
                    index+=x;
                    counter+=1;
                }
                else{break;}
            }
            cout<<"this is index : "<<index<<endl;
            text.erase(0,counter);
            counter=0;
            for (auto x:text){
                if (isspace(x)==0){
                    break;
                }
                else {counter+=1;}
            }
            text.erase(0,counter);
            counter=0;
            for (auto x:text){
                if (isspace(x)==0){
                    size+=x;
                }
                else{break;}
            }
            cout<<"this is size : "<<size<<endl;

            /*if (text[0] == 'a'){
                char ID = text[2];
                for (int i=3; i<text.size();i++){
                    alloc_size+=text[i];
                }
                cout<<"ID: "<<ID<<endl;
                cout<<"Alloc size : "<<alloc_size<<endl;
                alloc_size = "";
            }
            else if (text[0] == 'd'){

            }*/
        }
    }
    infile.close();
}
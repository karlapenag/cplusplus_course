#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream infile("twinkle.txt");
    int charCount = 0;
    while(infile.get() != EOF)
    {
        charCount++;
    }
    cout << "Character count: " << charCount << endl;
    infile.close();
    infile.open("twinkle.txt");
    int wordCount = 0;
    string word;
    while(infile >> word)
    {

        wordCount++;
    }
    cout << "Word count: " << wordCount << endl;
    infile.close();
    infile.open("twinkle.txt");
    int lineCount = 0;
    string line;
    while(getline(infile, line))
    {
        lineCount++;
    }
    cout << "Line count: " << lineCount << endl;

    infile.close();
    //second solution
    infile.open("twinkle.txt");
    lineCount = 0;
    wordCount = 0;
    charCount = 0;
    stringstream sstr;
    while(getline(infile, line))
    {
        lineCount++;
        charCount += line.length() + 1;
        sstr.str(line);
        while(sstr >> word)
        {
            wordCount++;
        }
        sstr.clear();

    }
    cout << "otherwise: " << endl;
    cout << "Character count: " << charCount << endl;
    cout << "Word count: " << wordCount << endl;
    cout << "Line count: " << lineCount << endl;

}

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

void printTokens(string str);

int main() {
    string myStr = "   The boy    ate    the apple   ";
    printTokens(myStr);
    /* expected output:
    The
    boy
    ate
    the
    apple
     */
    return 0;
}

void printTokens(string str)
{
    int  current = 0;
    int beginToken = 0, lengthToken = 0;
    while (current < str.length())
    {
        while(isspace(str[current]))
        {
            current++;
        }
        beginToken = current;
        while (!isspace(str[current]))
        {
            current++;
        }
        lengthToken = current - beginToken;
        cout << str.substr(beginToken, lengthToken) << endl;
    }
    // other solution involving stringstreams (not covered for Assignment 2)
    /*
    stringstream sstr(str);
    string token;
    while (sstr >> token)
    {
        cout << token << endl;
    }
     */
}
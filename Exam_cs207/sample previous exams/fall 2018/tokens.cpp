#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void intoTokens(string input, string* &tokens, int &nbrTokens);

int main()
{
    string* tokens = 0;
    int nbrTokens = 0;
    intoTokens("The boy ate the apple", tokens, nbrTokens);
    for(int i = 0; i < nbrTokens; i++)
    {
        cout << tokens[i] << endl;
    }
    delete[] tokens;
    return 0;
}

void intoTokens(string input, string* &tokens, int &nbrTokens)
{
    // insert code here
}


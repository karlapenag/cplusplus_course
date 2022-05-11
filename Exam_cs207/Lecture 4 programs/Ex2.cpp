#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    cout << "This program find whether two strings are equal ignoring case" << endl;
    cout << "Please enter the first string: ";
    string str1 = "";
    cin >> str1;
    //cout << "You entered: " << str1 << endl;

    cout << "Please enter the second string: ";
    string str2 = "";
    cin >> str2;
    //cout << "You entered: " << str2 << endl;

    if(str1.length() != str2.length())
    {
        cout << str1 << " and " << str2 << " are not equal ignoring case." << endl;
        return 0;
    }
    for(int i = 0; i < str1.length(); i++)
    {
        if(tolower(str1[i])!= tolower(str2[i]))
        {
            cout << str1 << " and " << str2 << " are not equal ignoring case." << endl;
            return 0;
        }
    }
    cout << str1 << " and " << str2 << " are equal ignoring case."  << endl;


    // solution 2
    string s1 = str1;
    string s2 = str2;
    for(int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    for(int i = 0; i < s2.length(); i++)
    {
        s2[i] = tolower(s2[i]);
    }
    // same loops with for-range
    /*
    for(auto& c : str1upper)
    {
        c = tolower(c);
    }

    for(auto& c : str2upper)
    {
        c = tolower(c);
    }
     */
    if(s1 == s2)
    {
        cout << str1 << " and " << str2 << " are equal ignoring case."  << endl;
    }
    else
    {
        cout << str1 << " and " << str2 << " are not equal ignoring case." << endl;
    }

    return 0;
}

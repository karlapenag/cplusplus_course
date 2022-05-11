#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Please enter the first string: ";
    string str1 = "";
    cin >> str1;
    cout << "You entered: " << str1 << endl;

    cout << "Please enter the second string: ";
    string str2 = "";
    cin >> str2;
    cout << "You entered: " << str2 << endl;

    // solution 1
    string str3 = "";
    for(int i = 0; i < str1.length(); i++)
    {
        if(str2.find(str1[i], 0) == string::npos)
        {
            str3 += str1[i];
        }
    }

    // same with for-range
    str3 = "";
    for(char c : str1)
    {
        if(str2.find(c) == string::npos)
        {
            str3 += c;
        }
    }

    //solution 2
    str3 = "";
    for(int i = 0; i < str1.length(); i++)
    {
        bool found = false;
        for(int j = 0; j < str2.length(); j++)
        {
            if(str1[i] == str2[j])
            {
                found = true;
            }
        }
        if(!found)
        {
            str3 += str1[i];
        }

    }
    //solution 3
    str3 = str1;
    for(int i = 0; i < str2.length() ; i++)
    {
        int pos = str3.find(str2[i]);
        while(pos != string::npos)
        {
            str3.erase(pos, 1);
            pos = str3.find(str2[i]);
        }
    }

    // solution 4
    string diff = str1;
    for(int i = 0; i < diff.length(); i++)
    {
        if(str2.find(diff[i]) != string::npos)
        {
            diff.replace(i, 1, "");
            i--;
        }
    }


    cout << "str3 = " << str3 << endl;
    return 0;
}

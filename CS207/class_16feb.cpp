//
// Created by Karla Angélica Peña Guerra on 2/16/22.
//
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout<<"Exercise 1"<<endl;
    cout<<"Enter Str1"<<endl;
    string str1;
    cin>> str1;
    cout<<"Enter Str2"<<endl;
    string str2;
    cin>> str2;
    string str3;
    for (int i =0; i<str1.length();i++)
    {
        if (str2.find(str1[i],0) == string::npos)
        {
            str3+=str1[i];
        }
    }
    cout<<str3<<endl;

    cout<<"Exercise 2"<<endl;
    cout<<"Enter Str1"<<endl;
    string str4;
    cin>> str4;
    cout<<"Enter Str2"<<endl;
    string str5;
    cin>> str5;
}

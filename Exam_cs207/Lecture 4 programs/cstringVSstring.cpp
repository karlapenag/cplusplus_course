#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    char s[32] = "spring";  //c-style string

    //s = "hello"; // no assignment allowed
    s[20] = 'B';
    s[6] = ',';
    cout << s << endl;

    char s1[] = "hello";
    cout << s1 << endl;
    s1[6] = 'c'; // no boundary check
    strcpy(s1, "world");
    cout << s1 << endl;
    // c++ string library
    string str1;
    string str2 = "hello";
    string str3(s);
    str1 = "world";
    cout << str1 << " " << str2 << " " << str3 << endl;
    cout << str2 + " to all the " + str1 << endl;
    cout << str3.length() << endl;
    string str4 = "123456";
    cout << str4 << endl;
    int i = stoi(str4);
    cout << i+2 << endl;
    str1[0] = 'v';
    cout << str1 << endl;

    cout << str4.substr(2, 3) << endl;

    if(int p = str4.find("12", 3) == string::npos)
    {cout << "not found" << endl;}
    else
    {cout << p << endl;}

    cin >> str1;
    cout << str1 << endl;


    return 0;
}
//
// Created by Karla Angélica Peña Guerra on 2/6/22.
//
#include <iostream>
using namespace std;

int main()
{
    int nValue = 5;
    int* ptr = &nValue;

    cout << &nValue << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(int*) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(double*) << endl;

    return 0;
}

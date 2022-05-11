//
// Created by Karla Angélica Peña Guerra on 1/30/22.
//
#include <iostream>
using namespace std;

int main()
{
    cout << "Insert temperature in Celsius: ";
    double c;
    cin >> c;
    cout << "Degrees in Fahrenheit: " << double(c*9/5+32);
}
//
// Created by Karla Angélica Peña Guerra on 2/2/22.
//
#include <iostream>
using namespace std;

const int myConstant = 10;
int foo();

int main()
{
    int x = 0;
    cin >> x;
    switch(x)
    {
        case 0:
            x++;
            break;
        case 1:
            x *= 2;
            break;
        case 2:
            cout << x << endl;
            break;
        default:
            x = 0;
    }
    return 0;
}

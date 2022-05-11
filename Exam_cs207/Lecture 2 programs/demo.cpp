//
// Created by smaouim on 9/10/2020.
//
#include <iostream>
using namespace std;

/* globals declarations */
const int myConstant = 10;

/* forward declarations */
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
    cout << "Hello" << endl;
    return 0;
}

int foo()
{
    cout << "myConstant = " << myConstant << endl;
    constexpr double myDouble = 0.1;
    cout << "myDouble = " << myDouble << endl;
    cout << "size of myDouble = " << sizeof(myDouble) << endl;

    return 0;
}


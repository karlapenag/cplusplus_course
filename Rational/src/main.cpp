#include <iostream>
#include "../include/Rational.h"
using namespace std;

int main() {
    Rational r1(24, -36);
    Rational r2(5, 2);
    cout << "r1 = ";
    r1.print();
    cout << "r2 = ";
    r2.print();
    cout << "r1 + r2 = ";
    Rational r3 = r1.add(r2);
    r3.print();
    //r1.add(r2).print();
    cout << "r1 - r2 = ";
    Rational r4 = r1.sub(r2);
    r4.print();
    cout << "r1 * r2 = ";
    Rational r5 = r1.mul(r2);
    r5.print();
    cout << "r1 / r2 = ";
    Rational r6 = r1.div(r2);
    r6.print();

    Rational r7(-2, 3);
    if(r1.equals(r7))
    {
        cout << "r1 is equal to r7" << endl;
    }

    cout << "r7 = " << r7.toString() << endl;

    cout << r1.compareto(r2) << endl;

    return 0;
}
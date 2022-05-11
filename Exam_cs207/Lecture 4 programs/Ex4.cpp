#include <iostream>
using namespace std;

int main()
{
    struct fraction{
        int numerator;
        int denominator;
        };

    fraction f1 {0,1} , f2 {0, 1};
    cout << "Please enter the numerator and denominator of the first fraction, separated by a space: ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Please enter the numerator and denominator of the second fraction, separated by a space: ";
    cin >> f2.numerator >> f2.denominator;

    fraction f3 {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
    //f3.numerator = f1.numerator * f2.numerator;
    //f3.denominator = f1.denominator * f2.denominator;
    cout << "The product of these two fractions is: " << f3.numerator << "/" << f3.denominator ;
    cout << " = " << (double) f3.numerator / f3.denominator << endl;

    return 0;
}

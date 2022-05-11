//
// Created by smaouim on 10/7/2019.
//

#include "Rational.h"
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

Rational::Rational(long int n, long int d)
{
    if(d == 0)
    {
        d = 1;   // design decision
        //exit(-1);   // other deign decision
    }
    if(d < 0)
    {
        d *= -1;
        n *= -1;
    }
    long int gcd = GCD(abs(n), abs(d));
    if (n != 0)
    {
        n /= gcd;
        d /= gcd;
    }
    numerator = n;
    denominator = d;
}

void Rational::print() {
    cout << numerator << "/" << denominator << endl;
}

Rational Rational::add(Rational r) {
    //long int n = numerator * r.denominator + r.numerator * denominator;
    //long int d = denominator * r.denominator;
    //Rational res(n, d);
    //return res;
    return Rational(numerator * r.denominator + r.numerator * denominator, denominator * r.denominator);
}

Rational Rational::sub(Rational r) {
    long int n = numerator * r.denominator - r.numerator * denominator;
    long int d = denominator * r.denominator;
    Rational res(n, d);
    return res;
    //return Rational(numerator * r.denominator - r.numerator * denominator, denominator * r.denominator);
}

Rational Rational::mul(Rational r) {
    long int n = numerator *  r.numerator;
    long int d = denominator * r.denominator;
    Rational res(n, d);
    return res;
    //return Rational(numerator * r.numerator, denominator * r.denominator);
}

Rational Rational::div(Rational r) {
    long int n = numerator * r.denominator;
    long int d = denominator * r.numerator;
    Rational res(n, d);
    return res;
    //return Rational(numerator * r.denominator , denominator * r.numerator);

}

bool Rational::equals(Rational r) {

    return numerator == r.numerator && denominator == r.denominator;
}

long int Rational::compareto(Rational r) {
    //long int n = numerator * r.denominator - r.numerator * denominator;
    //long int d = denominator * r.denominator;
    //Rational res(n, d);
    //return res.numerator;
    Rational res = this->sub(r);
    return res.numerator;
}

string Rational::toString() {
    if(denominator != 1)
        return to_string(numerator) + "/" + to_string(denominator);
    else
        return to_string(numerator);
    stringstream sstr;
    sstr << numerator;
    if(denominator != 1)
    {
        sstr << "/" << denominator;
    }
    return sstr.str();
}

long int GCD(long int a, long int b)
{
    if( a * b == 0)
        return 0;
    while(b != 0)
    {
        long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
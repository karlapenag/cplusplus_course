//
// Created by smaouim on 10/7/2019.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H
#include <string>
using namespace std;

class Rational {
private:
    long int numerator;
    long int denominator;


public:
    Rational(long int n =0, long int d = 1);
    void print();
    Rational add(Rational r);
    Rational sub(Rational r);
    Rational mul(Rational r);
    Rational div(Rational r);
    bool equals(Rational r);
    long int compareto(Rational r);
    string toString();
};

long int GCD(long int a, long int b);

#endif //RATIONAL_RATIONAL_H

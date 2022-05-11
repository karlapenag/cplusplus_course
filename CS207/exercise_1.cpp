//
// Created by Karla Angélica Peña Guerra on 2/8/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

int main() {
    cout << " EXERCISE 1 " << endl;
    cout << " This program computes an approximation of π using the first 10,000 terms of the Leibniz's series."
    << endl;
    // The Leibniz series uses the following mathematical relationship:
    // pi/4 = 1-1/3+1/5-1/7+1/9-1/11+...

    double odds = 1; // first odd number in series
    double sum = 0;
    for (int i = 0; i < 10000; i++) // run a thousand times and increase 'i' by 1 every un
    {
        // if 'i' is an even number (starting with zero), add the division of 1 by the odd number,
        // if it's odd then subtract the division of 1 by the odd number
        (i % 2 == 0) ? sum = sum + 1/odds : sum = sum - 1/odds;// ternary operator; short for if/else statement.
        odds = odds + 2; // operation to use only odd numbers in denominator
    }
    cout << " : π approximation is " << 4*sum << endl;

    return 0;
}

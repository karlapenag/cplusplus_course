//
// Created by Karla Angélica Peña Guerra on 2/8/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

int main() {
    cout << " EXERCISE 2 " << endl;
    cout << " This program computes the digital root of an integer value." << endl;
    // The digital root is defined as the result of summing the digits repeatedly until only a single digit remains.
    // -The negative sign of negative integers should not affect their digital root
    int n;
    cout << " Enter an integer: ";
    cin >> n;
    int div = abs(n); // make absolute value so that negative numbers don't affect
    int size = std::to_string(div).length(); // get number of digits in integer
    while (size > 1) // will be running until the sum consists of only one digit
    {
        int sum = 0;
        for (int i =0; i < size; i++) // will run for as many digits as the sum has
        {
            int residue = div % 10;  // gets the value at the ones position (rightmost)
            sum = sum + residue;  // adds every digit in the number
            div = div/10;  // operation to get rid of the rightmost number
        }
        div = sum; // the evaluated number will now be the new sum
        size = std::to_string(sum).length(); // re-define the variable 'size' so that
        // the 'for loop' will now run for as many digits as the new sum has
    }
    cout << " : The digital root of " << n << " is " << div << "." << endl;
    return 0;
}
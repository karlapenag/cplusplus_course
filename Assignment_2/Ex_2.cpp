//
// Created by Karla Angélica Peña Guerra on 2/22/22.
//
// CS 207
// 180951
#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << " EXERCISE 2 " << endl;
    cout << " This program adds long integers as strings" << endl;
    cout << "Please type-in the first integer: " << endl;
    string first;
    cin >> first;
    cout << "Please type-in the second integer: " << endl;
    string second;
    cin >> second;

    string max;
    string min;

    // default: they are the same size hence doesn't matter who's the max or min
    max = first;
    min = second;

    // check if there is a longer number to accurately assign the max or min title depending on the subtraction
    int checkMax = first.length() - second.length();

    if (checkMax<0){ // if the result is negative, the second integer is longer
        max = second;
        min = first;
    }
    else if (checkMax>0){ //if the result is positive, the first integer is longer
        max = first;
        min = second;
    }

    // store the number of digits longer (they will have to be added separately)
    int digitsLeft = max.length() - min.length();

    int carry = 0; // variable to keep track of carry in further calculations
    string sum; // string that will store the results of the arithmetic operations

    for (int i = min.length() - 1; i < min.length(); i--) { // for loop that will run as many times as the number of digits
        // of the number with fewer digits, starting from the rightmost digit (min.length()-1) and moving left.
        int ans= (max[i+digitsLeft]-'0') + (min[i]-'0') + carry; // arithmetic operations
        // "-'0'" to use the numbers and not their ASCII values subtracting 48 (=0).
        string NumToStr = std::to_string(ans % 10); // get the digit in the ones position
        sum = NumToStr + sum; // update 'sum' concatenating the digits at the beginning (left) of the string
        carry = ans / 10;  // get the carry
    }
    for (int i = digitsLeft - 1; i >= 0; i--){ // for loop to add the digits left of the number with more digits
        sum = max[i] + sum;
    }
    cout << "The sum of these two numbers is: " << sum << endl;
    return 0;
}

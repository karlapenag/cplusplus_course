#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter an integer: ";
    int number = 0;
    cin >> number;
    string numberAsString = "";
    int temp = number;
    bool negative = false;
    if(temp < 0)
    {
        negative = true;
        temp *= -1;
    }
    else if (temp == 0)
    {
        numberAsString = "0";
    }
    while (temp > 0)
    {
        int rightDigit = temp%10;
        char rightDigitChar = rightDigit+'0'; //rightDigit+48
        numberAsString = rightDigitChar+numberAsString;
        temp /= 10;
    }
    //second solution
    /*
    string digits = "0123456789";
    while (temp > 0)
    {
        int rightDigit = temp%10;
        numberAsString = digits[rightDigit]+numberAsString;
        temp /= 10;
    }
     */

    if(negative)
    {
        numberAsString = '-' + numberAsString;
    }

    cout << "Checking corresponding string: " << numberAsString << endl;
    return 0;
}

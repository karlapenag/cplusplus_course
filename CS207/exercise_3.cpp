//
// Created by Karla Angélica Peña Guerra on 2/9/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

int main() {
    cout << "EXERCISE 3 " << endl;
    cout << "This program prints the details of reducing a positive integer to zero. "
         << endl;
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    while (n > 0)  //  program stops when the user enters zero or a negative number
    {
        int ans = n;
        while (ans != 0) // will run until the answer reduction reaches 0
        {
            if (ans % 2 == 0) // if the number is even divide it by 2
            {
                cout << ans << " / 2 = "; // print without ending line
                ans = ans / 2; // update variable
                cout << ans << endl; // continue print with division answer
            }
            else // if the number is odd subtract 1
            {
                cout << ans << " - 1 = "; // print without ending line
                ans = ans - 1; // update variable
                cout << ans << endl; // continue print with subtraction answer
            }
        }
        cout << "Enter a positive integer: ";
        cin >> n;
    }
    return 0;
}

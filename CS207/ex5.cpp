//
// Created by Karla Angélica Peña Guerra on 2/6/22.
//
#include <iostream>
using namespace std;

int main()
{
    cout << " This program finds the maximum of a sequence of user-provided values. Enter 0 to signal the end of the list." << endl;
    double max = 0;
    double userEntry = 0;
    cout << "? ";
    cin >> userEntry;
    while (userEntry != 0)
    {
        if (userEntry > max)
        {
            max = userEntry;
        }
        cout << "? ";
        cin >> userEntry;
    }
    cout << "The maximum is: " << max << endl

    return 0;
}

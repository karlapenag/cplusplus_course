//
// Created by Karla Angélica Peña Guerra on 2/6/22.
//
#include <iostream>
using namespace std;

int main()
{
    cout << " This program finds the maximum of a sequence of user-provided values. Enter 0 to signal the end of the list." << endl;
    double userEntry = 0;
    cout << "? ";
    cin >> userEntry;
    double max = userEntry;
    cout << "? ";
    cin >> userEntry;
    double secondMax = 0;
    if (userEntry < max)
    {
        secondMax = userEntry;
    }
    else
    {
        secondMax = max;
        max = userEntry;
    }
    while (userEntry != 0)
    {
        if (userEntry > max)
        {
            secondMax = max;
            max = userEntry;
        }
        else if (userEntry > secondMax && userEntry != max)
        {
            secondMax = userEntry;
        }
        cout << "? ";
        cin >> userEntry;
    }
    cout << "The maximum is: " << max << endl;
    cout << "The second maximum is: " << secondMax << endl;

    return 0;


}

//
// Created by Karla Angélica Peña Guerra on 3/27/22.
//
#include <iostream>

using namespace std;

bool isSorted(int values[], int n);

int main()
{
    int a[7] = {2, 5, 6, 8, 11, 12, 24 };
    int b[7] = {10, 20, 40, 30, 50, 60, 70};

    if(isSorted(a, 7))
    {
        cout << "The array a is sorted" << endl;
    }
    else
    {
        cout << "The array a is not sorted" << endl;
    }
    if(isSorted(b, 7))
    {
        cout << "The array b is sorted" << endl;
    }
    else
    {
        cout << "The array b is not sorted" << endl;
    }
}

bool isSorted(int values[], int n)
{
    for(int i = 0; i <= n-2; i++)
    {
        if(values[i+1] < values[i])
        {
            return false;
        }
    }
    return true;
}

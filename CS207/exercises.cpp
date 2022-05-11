//
// Created by Karla Angélica Peña Guerra on 2/2/22.
//
#include <iostream>
using namespace std;

int main()
{
    int N;
    int i = 1;
    int odds = 1;
    int sum = 0;
    cout << "Enter N: " << endl;
    cin >> N;
    while (i <= 4){
        if (double(odds % 2) != 0) {
            i += 1;
            sum += odds;
            odds += 1;
        }
    }
    cout << sum;
}




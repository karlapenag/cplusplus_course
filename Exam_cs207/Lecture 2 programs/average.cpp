#include <iostream>
using namespace std;

int main()
{
    cout << "How many values would you like to average? ";
    int nbrValues = 0;
    cin >> nbrValues;
    double sum = 0.0;
    double value;
    for(int i = 0; i < nbrValues; i++)
    {
        cout << "Please enter a value: ";
        cin >> value;
        sum += value;
    }
    cout << "The average is " << sum / nbrValues << endl;

    return 0;
}

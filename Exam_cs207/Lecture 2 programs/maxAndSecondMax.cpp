#include <iostream>
using namespace std;

const int SENTINEL = 0;
int main()
{
    cout << "This program finds the maximum in a sequence of integer values" << endl;
    cout << "Enter " << SENTINEL << " to signal the en d of the sequence." << endl;

    int userInput;
    cout << "? ";
    cin >> userInput;
    if(userInput == SENTINEL)
    {
        cout << "The list is empty." << endl;
        return 0;
    }
    int maximum = userInput;
    cout << "? ";
    cin >> userInput;
    if(userInput == SENTINEL)
    {
        cout << "The maximum of the list is: " << maximum << endl;
        cout << "The list has only one value. There is no second largest value." << endl;
        return 0;
    }
    int sdMax;
    if(userInput > maximum)
    {
        maximum = userInput;
        sdMax = maximum;
    }else
    {
        sdMax = userInput;
    }

    while(userInput != SENTINEL)
    {
        if(userInput >= maximum)
        {
            maximum = userInput;
            sdMax = maximum;
        }
        else if(userInput >= sdMax)
        {
            sdMax = userInput;
        }
        cout << "? ";
        cin >> userInput;
    }

    cout << "The maximum of the list is: " << maximum << endl;
    cout << "The second largest value of the list is: " << sdMax << endl;

    return 0;

}

#include <iostream>
using namespace std;

const int SENTINEL = 0;
int main()
{
    cout << "This program finds the maximum in a sequence of integer values" << endl;
    cout << "Enter " << SENTINEL << " to signal the end of the sequence." << endl;

    int userInput;
    cout << "? ";
    cin >> userInput;
    if(userInput == SENTINEL)
    {
        cout << "The list is empty." << endl;
        return 0;
    }
    int maximum = userInput;
    while(userInput != SENTINEL)
    {
        if(userInput > maximum)
        {
            maximum = userInput;
        }
        cout << "? ";
        cin >> userInput;
    }

    cout << "The maximum of the list is: " << maximum << endl;

    return 0;

}

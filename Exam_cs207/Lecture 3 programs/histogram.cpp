#include <iostream>

using namespace std;

int main()
{
    cout << "This program prints a histogram of scores." << endl;
    int range[11] = {0}; // we use a static array because its size is known at compile time,
    // Elements need to be all initialized to 0 because they are accumulators.
    // Even if they are not accumulators, initialization is always a good practice.
    int score = 0;
    cout << "Please enter a score. Enter a negative value to get the histogram. " << endl;
    cin >> score;
    while(score >= 0 && score <= 100)
    {
        range[score/10]++;
        cout << "Please enter a score. Enter a negative value to get the histogram. " << endl;
        cin >> score;
    }
    // printing horizontally
    for(int i = 0; i <= 10; i++)
    {
        if (i == 0)
        {
            cout << "0-9  :";
        }
        else if(i < 10)
        {
            cout << i*10 << "-" << i*10+9 << ":";
        }
        else
        {
            cout << i*10 << "  :";
        }

        for(int j = 0; j < range[i]; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    cout << "This program prints a histogram of scores." << endl;
    int range[11] = {0};
    int score = 0;
    // reading scores from a file. Scores are space-separated.
    /*ifstream input("../scores.txt"); // avoids call to open as in input.open("scores.txt");
    if(input.fail()) // can also use input.is_open()
    {
        cout << "could not open input file" << endl;
        return 1;
    }
    while(true)
    {
        input >> score;
        if(input.fail())
            break;
        if(score >= 0 && score <= 100)
        {
            range[score/10]++;
        }
    }

    input.close();*/
    // reading space-separated scores from standard input
    cout << "Please enter space-separated scores: " << endl;
    string userEntry;
    getline(cin, userEntry);
    stringstream userStream(userEntry);
    while(userStream >> score)
    {
        if(score >= 0 && score <= 100)
        {
            range[score/10]++;
        }
    }
    // printing horizontally
    /*for(int i = 0; i <= 10; i++)
    {
        if(i < 10)
        {
            cout << i*10 << "-" << i*10+9 << ":";
        }
        else
        {
            cout << i*10 << ":";
        }

        for(int j = 0; j < range[i]; j++)
        {
            cout << '*';
        }
        cout << endl;
    }*/

    //printing vertically
    int maxVal = 0;
    for(int x : range)
    {
        if(x >= maxVal)
            maxVal = x;
    }

    for(int i = maxVal; i > 0 ; i--)
    {
        for(int j = 0; j <= 10; j++)
        {
            if(range[j] >= i)
            {
                cout  << left << setw(7) << "*"; //
            }
            else
            {
                cout  << left << setw(7) << " ";//
            }

        }
        cout << endl;
    }
    for(int j = 0; j < 10; j++)
    {
        cout << left << setw(2) << j*10 << "-"  << setw(4) << j*10+9;
    }
    cout  << left << setw(7) << "100" << endl;

    return 0;
}

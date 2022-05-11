#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void printArrowToFile(int n);
int main()
{
    int n = 0;
    cout << "n= ";
    cin >> n;

    printArrowToFile(n);
    /*for(int i = n; i > 0; i--)
    {
        cout << right << setw(i) << '*' << endl;
    }
    cout << setfill('*') << setw(3*n) << '*' << endl;
    cout << setfill(' ');
    for(int i = 1; i <= n; i++)
    {
        cout << right << setw(i) << '*' << endl;
    }*/

        return 0;
}

void printArrowToFile(int n)
{
    string filename = "arrow_" + to_string(n) + ".txt";
    ofstream arrowfile(filename);
    for(int i = n; i > 0; i--)
    {
        arrowfile << right << setw(i) << '*' << endl;
    }
    arrowfile << setfill('*') << setw(3*n) << '*' << endl;
    arrowfile << setfill(' ');
    for(int i = 1; i <= n; i++)
    {
        arrowfile << right << setw(i) << '*' << endl;
    }
    arrowfile.close();
}
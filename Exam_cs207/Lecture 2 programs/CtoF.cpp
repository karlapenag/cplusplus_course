#include <iostream>
using namespace std;

int main()
{
    cout << "This program converts a temperature in Celsius to Farenheit" << endl;
    cout << "Please enter a temperature in degree celsius: ";
    double celsius = 0;
    cin >> celsius;
    double fahrenheit =  9.0 / 5 * celsius + 32;
    cout << celsius << " C = " << fahrenheit << " F" << endl;
    return 0;
}

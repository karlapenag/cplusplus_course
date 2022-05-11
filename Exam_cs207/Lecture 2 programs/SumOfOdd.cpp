#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter a positive integer :" ;
    int N = 0;
    cin >> N;

    int sum = 0;
    /* first solution */
    /* for(int i = 0; i < N; i++)
    {
        sum += 2 * i + 1;
    }*/

    /* second solution */
    /*for(int i = 0; i < 2*N; i++)
    {
        if(i % 2 == 1)
        {
            sum += i;
        }
    }*/

    /* third solution */
    int odd = 1;
    int counter = 1;
    while(counter <= N)
    {
        sum += odd;
        odd += 2;
        counter++;
    }

    cout << "The sum of the first " << N << " odd numbers is: " << sum << endl;
    return 0;
}

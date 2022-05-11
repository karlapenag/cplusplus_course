#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "This program computes the mean and standard deviation of a sample of floating point values." << endl;
    cout << "How many values do you have? ";
    int sampleSize = 0;
    cin >> sampleSize;
    // you could do some input validation here. but, we didn't cover streams in details yet.
    if(sampleSize <= 0)
    {
        cout << "Negative or null number of values. Aborting ..." << endl;
        return 0;
    }
    //double sample[sampleSize]; // static array not allowed because sampleSize is not a constant
    double* sample = new double[sampleSize] {0.0};
    double mean = 0.0;
    for(int i=0; i < sampleSize; i++)
    {
        cout << "? ";
        cin >> sample[i];
        mean += sample[i];
    }
    mean /= sampleSize;
    double stdDev = 0.0;
    for(int i=0; i < sampleSize; i++)
    {
        stdDev += (sample[i] - mean) * (sample[i] - mean);
    }
    if (sampleSize > 1)
    {
        stdDev = sqrt(stdDev / (sampleSize - 1));
    }
    else
    {
        stdDev = 0;
    }


    cout << "The mean of your sample is " << mean << endl;
    cout << "The standard deviation of your sample is " << stdDev << endl;

    // explicit de-allocation is required to avoid memory leaks
    delete[] sample;

    return 0;
}

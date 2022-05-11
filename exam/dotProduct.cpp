//
// Created by Karla Angélica Peña Guerra on 3/27/22.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double dotProduct(double* v1, double* v2, int dim);

int main()
{
    const int dim = 5;
    double* vect1 = new double[dim]{0.0};
    double* vect2 = new double[dim]{0.0};
    cout << "The dot product of [";
    for(int i = 0; i < dim; i++)
    {
        vect1[i] = (double)rand()/RAND_MAX;
        cout << vect1[i] << " " ;
    }
    cout << "] and [";
    for(int i = 0; i < dim; i++)
    {
        vect2[i] = (double)rand()/RAND_MAX;
        cout << vect2[i] << " " ;
    }
    cout << "] is " << dotProduct(vect1, vect2, dim) << endl;
}

double dotProduct(double* v1, double* v2, int dim)
{
    double dp = 0.0;
    for(int i = 0; i < dim; i++)
    {
        dp += v1[i]*v2[i];
    }
    return dp;
}

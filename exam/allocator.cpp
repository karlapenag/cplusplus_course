//
// Created by Karla Angélica Peña Guerra on 3/27/22.
//
#include <iostream>
using namespace std;

int* initArray(int dim);
void initArray(int* &p, int dim);

int main()
{
    int* q = nullptr;
    initArray(q, 10);
    cout << q << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    delete[] q;

    int* r = initArray(10);
    cout << r << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << r[i] << " ";
    }


    delete[] r;
    return 0;
}

int* initArray(int dim)
{
    //not a compile error but bug
    //int p[5] = {1, 2, 3, 4, 5};
    int* p = new int[dim];
    for(int i = 0; i < dim; i++)
    {
        p[i] = i+1;
    }
    return p;
}

void initArray(int* &p, int dim)
{
    p = new int[dim];

    for(int i = 0; i < dim; i++)
    {
        p[i] = 2*i;
    }
    // not a compile error but bug!!
    //int x = 5;
    //p = &x;
}

//
// Created by Karla Angélica Peña Guerra on 2/23/22.
//
#include <iostream>

using namespace std;

int* zerosArray(int n)
{
    int* ptr=new int[n]{0};
    return ptr;
}
int* sampleFunction(int* array, int index)
{
    return &array[index];
}
int add(int a, int b){
    return a+b;
}

int main()
{

    delete[] zeros;
}
//
// Created by Karla Angélica Peña Guerra on 2/23/22.
//
#include <iostream>
using namespace std;

bool isSorted(int myArray[], int n) // array = integer array, n = effective size
{
    for (int i =0; i<n;i++){
        if (myArray[i]>=myArray[i+1]){
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    int myArray[]={9,8,2,1};
    int arrSize = sizeof(myArray)/sizeof(myArray[0]);
    bool result = isSorted(myArray, arrSize);
    cout << result << endl;
}

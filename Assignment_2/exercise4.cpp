//
// Created by Karla Angélica Peña Guerra on 2/23/22.
//

#include <iostream>
using namespace std;
void arrayN(int n){
    int* myArray=new int[n];
    for (int i=1; i<n+1;i++){
        myArray[i]=i;
        cout<<myArray[i];
    }
}
void ptrArray(int* &myArray, int n){
    for (int i=1;i<n+1;i++)
    {
        myArray[i]=i;
    }

}
int main(){
    int result=arrayN(6);
    ptrArray(result,6);

}
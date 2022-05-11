//
// Created by Karla Angélica Peña Guerra on 2/9/22.
//
#include <iostream>
using namespace std;

int main() {
    // to comment faster /* +/
    int a[100],n,i,j;

    cout<<"Enter Size of Array"<<endl;
    cin>>n;

    cout<<"Enter Array Elemnts"<<endl;

    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    for(i=0;i<n;i++) {
        for(j=0;j<a[i];j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

//
// Created by Karla Angélica Peña Guerra on 2/21/22.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    char szString[] = "string";
    cout<<szString<<endl;

    struct Employee
    {
        string fullName;
        int nID;
        int nAge;
        float fWage;
    };
    Employee sJoe; //declaration of an uninitialized variable of type Employee
    cout << "The size of Employee is " << sizeof(Employee);
// prints the size of a variable of type Employee
}

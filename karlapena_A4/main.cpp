#include <iostream>
#include<ostream>
#include "LinkedList.h"

using namespace std;

int main() {
    cout << "Assignment 4" << endl;
    cout << endl;

    List list1;

    // Inserting nodes
    List::append(list1, 1);
    List::append(list1, 3);
    List::prepend(list1, 4);  //prepend
    List::append(list1, 0);
    List::prepend(list1, 6);  //prepend

    cout << "Elements of list1 (before removing elements) are: ";
    // Print the list using print member function
    List::print(list1);
    cout << endl;

    // Delete keys from nodes
    List::remove(list1, 4);
    List::remove(list1, 1);
    List::remove(list1, 2);

    // printing using print member function
    cout << "Elements of list1 (after removing 4,1,2) are: ";  // 2 is not in the list
    List::print(list1);
    cout << endl;

    // create list from array
    int a[]  = {9,1,5,3,4};
    List list2(a);

    // append an integer to a list
    List list3 = list2 + 5; // Here copy constructor is called

    // prepend and integer **ERROR**
    // List list5 = 5 + list2;

    // append a list to a list
    int b[] = {6,7,8,0};
    List list4 = list3 + b; // Here copy constructor is called

    cout << endl; // indent after copy constructor calls

    // printing using overload <<
    cout << "Elements of list2 are: ";
    cout << list2;
    cout << endl;

    cout << "Elements of list3 (list2 + (int 5)) are: ";
    cout << list3;
    cout << endl;

    cout << "Elements of list4 (list3 + other list) are: ";
    cout << list4;
    cout << endl;

    int index = 2;  // arbitrary number for index
    cout << "Element in index '" << index << "' of list4 is: ";
    cout << list4[index] << endl;
    cout << endl;

    // assignment operator
    list1 = list4;

    cout << "Elements of new list1 (= list4) are: ";
    cout << list1;
    cout << endl;

    // destructor (??)
    list1.~List();
    list2.~List();
    list3.~List();
    list4.~List();

    return 0;
}

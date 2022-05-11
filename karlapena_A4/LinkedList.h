//
// Created by Karla Angélica Peña Guerra on 4/17/22.
//
#include<iostream>
#include<ostream>
#include<string>
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

using namespace std;

class List{
private:
    struct node{
    public:
        int data;
        node* next;
        node* previous;
    };
    node* head;
    node* tail;
public:
    List(); // default constructor creates empty list
    ~List(); // destructor
    explicit List(int[]); // parametrized constructor (array input)

    /*
    Difference between Copy Constructor and Assignment operator:
    - If a new object has to be created before the copying can occur, the copy constructor is used (note: this includes passing or returning objects by value).
    - If a new object does not have to be created before the copying can occur, the assignment operator is used
     */

    List(const List& copy) : head { copy.head }, tail { copy.tail }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    // Overloaded assignment operator
    List& operator=(const List& list);

    // List operator+(List&);   // prepend integer **ERROR**
    List operator+(int int1) const;  // append integer
    List operator+(int[]) const;  // concatenate list
    int operator[](int);  // overload operator []
    friend ostream& operator<<(ostream& os, const List&); // overload operator <<

    static bool isEmpty(const List&);
    static void print(const List&);
    static void prepend(List&, int);
    static void append(List&, int);
    static bool find(const List&, int);
    static void pop(List&);
    static void popBack(List&);
    static void remove(List&, int);
};


#endif //LINKEDLIST_LINKEDLIST_H

//
// Created by Karla Angélica Peña Guerra on 4/17/22.
//
#include "LinkedList.h"
#include <iostream>
#include<ostream>

using namespace std;

//Constructor
List::List(){
    head = nullptr;
    tail = nullptr;
}

//Destructor  (got message with 'use default' recommendation after implementing it hard-coded)
List::~List() = default; /*{
        if (head != nullptr){
            node *temp = head;
            while (temp != nullptr){
                node *nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }
        }
}*/

//parametrized constructor
List::List(int myArray[]){
    head = nullptr;
    tail = nullptr;
    for (int i=0; i<=sizeof(*myArray);i++){
        append(*this,myArray[i]);
    }
}

bool List::isEmpty(const List& list1)
{
    if(list1.head == nullptr && list1.tail == nullptr)
        return true;
    return false;
}
void List::append(List &l1, int data)
{
    node* node1 = new node{data, nullptr, l1.tail};
    if(l1.head == nullptr && l1.tail == nullptr)
    {
        l1.head = node1;
        l1.tail = node1;
    }
    else
    {
        l1.tail->next = node1;
        l1.tail = node1;
    }
}

void List::print(const List& l1)
{
    if(isEmpty(l1))
    {
        cout << "List is empty" << endl;
        return;
    }
    node* traveller = l1.head;
    while(traveller != l1.tail)
    {
        cout << traveller->data << "=>";
        traveller = traveller->next;
    }
    cout << l1.tail->data << endl;
}

std::ostream& operator<<(std::ostream& os, const List &l1)
{
    List::node* traveller = l1.head;
    while(traveller != l1.tail)
    {
        os << traveller->data << "=>";
        traveller = traveller->next;
    }
    os << l1.tail->data << endl;
    return os;
}

void List::prepend(List &l1, int data)
{
    node* node1 = new node{data, l1.head, nullptr};
    if(l1.head == nullptr && l1.tail == nullptr)
    {
        l1.head = node1;
        l1.tail = node1;
    }
    else
    {
        l1.head->previous = node1;
        l1.head = node1;
    }
}

bool List::find(const List& l1, int key)
{
    // returns a pointer to the first occurrence of the key in the list
    node* traveller = l1.head;
    while(traveller != l1.tail->next)
    {
        if(traveller->data == key)
        {
            return true;
        }
        traveller = traveller->next;
    }
    return false;
}

void List::pop(List &list1)
{
    if (isEmpty(list1))
        return;
    if(list1.head == list1.tail) // one node
    {
        delete list1.head;
        list1.head = nullptr;
        list1.tail = nullptr;
        return;
    }
    node* firstNode = list1.head;
    list1.head = list1.head->next;
    list1.head->previous = nullptr;
    delete firstNode;
}

void List::popBack(List &list1)
{
    if (isEmpty(list1))
        return;
    if(list1.head == list1.tail) // one node
    {
        delete list1.head;
        list1.head = nullptr;
        list1.tail = nullptr;
        return;
    }
    node* lastNode = list1.tail;
    list1.tail = list1.tail->previous;
    list1.tail->next = nullptr;
    delete lastNode;
}

void List::remove(List &list1, int key)
{
    if(find(list1, key))
    {
        node* traveller = list1.head;
        while(traveller != list1.tail->next)
        {
            if(traveller->data == key)
            {
                if(traveller == list1.head)
                {
                    pop(list1);
                    return;
                }
                else if(traveller == list1.tail)
                {
                    popBack(list1);
                    return;
                }
                else if(traveller)
                {
                    node* tempPrev = traveller->previous;
                    node* tempNext = traveller->next;
                    tempPrev->next = tempNext;
                    tempNext->previous = tempPrev;
                    delete traveller;
                }
            }
            traveller = traveller->next;
        }
    }
    else
    {
        cout << "Key '"<< key << "' not in list." << endl;
    }
    // note that this deletes only the first occurrence of the key in the list
}

// overload + operator to prepend an integer **ERROR**
/*List List::operator+(List &l1){
    List *result = new List;
    *result = *this;
    prepend(*result);
    return *result;
}*/

// overload + operator to append an integer
List List::operator+(const int int1) const {
    List *result = new List;
    *result = *this;
    append(*result,int1);
    return *result;
}

// overload + operator to concatenate a list
List List::operator+(int myArray[]) const {
    List *result = new List;
    *result = *this;
    for (int i=0; i<sizeof(*myArray);i++){
        append(*result,myArray[i]);
    }
    return *result;
}

// overload assignment operator (got message with 'use default' recommendation after implementing it hard-coded)
List& List::operator= (const List& list1)
= default;

// overload [] operator to find data in index
int List::operator[](int index) {
    node* current = this->head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index) {
            return (current->data);
        }
        count++;
        current = current->next;
    }
    cout << "Index not found."<<endl;
    return -1;
}


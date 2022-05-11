//
// Created by Karla Angélica Peña Guerra on 2/27/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* previous;
};

struct list{
    node* head;
    node* tail;
};

int main(){
    list* myList = new list {nullptr,nullptr};
    node* node1 = new node{8, nullptr, nullptr};
    myList->head = node1;  // address of node1 to myList.head
    myList->tail = node1; // address of node1 to myList.tail

    node1 = new node{10, nullptr, nullptr};
    myList->tail->next = node1;
    node1->previous=myList->tail;
    myList->tail=node1;

    /* node* first = myList->head;
    first->next = node1;
    myList->tail = node1;
    myList->head->next = node1;
    node1->previous = myList->head;
    myList->tail = node1; */

    node1=new node{-1, nullptr, nullptr};
    myList->tail->next = node1;
    node1->previous=myList->tail;
    myList->tail=node1;

    node1=new node{-20, nullptr, nullptr};
    myList->tail->next = node1;
    node1->previous=myList->tail;
    myList->tail=node1;

    node* traveller = myList->head;
    while(traveller != nullptr)
    {
        cout << traveller->data << endl;
        traveller = traveller -> next;
    }
    return 0;
}


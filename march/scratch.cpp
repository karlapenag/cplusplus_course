//
// Created by Karla Angélica Peña Guerra on 3/9/22.
//
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
void appendList(list &l1, int data){
    node* node1 = new node{data, nullptr, l1.tail};
    //node1->previous=l1.tail
    if(l1.head == nullptr && l1.tail == nullptr){
        l1.head=node1;
        l1.tail=node1;
    }
    else{
        l1.tail->next=node1;
        l1.tail=node1;
    }

}
void appendList(list* pl1, int data){
    node* node1=new node{data, nullptr, pl1->tail};
    if(pl1->head== nullptr&&pl1->tail== nullptr){
        pl1->head=node1;
        pl1->tail=node1;
    }
    else{
        pl1->tail->next=node1;
        pl1->tail=node1;
    }
}

void printList(list l1){
    node* traveller=l1.head;
    while(traveller!= l1.tail)
    {
        cout << traveller->data << "=>";
        cout << traveller->data;
        traveller=traveller->next;
    }
    cout<<l1.tail->data<<endl;
}

node* findInList(list l1, int key){
    node* traveller=l1.head;
    while(traveller!= l1.tail->next)
    {
        if(traveller->data==key){
            return traveller;
        }
        traveller=traveller->next;
    }
    cout<<"Key not found"<<endl;
    return 0;
}
int main() {
    /*list* myList = new list{nullptr, nullptr};
    list list1{nullptr,nullptr};


    list1.head=node1;
    list1.tail=node1;

    node* node1 = new node{8, nullptr, nullptr};
    myLIst->head->next=node1;
    node1->previous=myList->head;
    myList->tail->next=node1;
    node1->previous=myList->tail;
    myList->tail=node1;

    node1 = new node{10, nullptr, nullptr};
    myList->head->next=node1;
    node1->previous=myList->head;*/
    list* myList=new list{nullptr, nullptr};
    list list1{nullptr, nullptr};

    appendList(*myList, 10);
    appendList(*myList, 20);
    appendList(*myList, 30);
    printList(list1);

    node* traveller = list1.head;

}

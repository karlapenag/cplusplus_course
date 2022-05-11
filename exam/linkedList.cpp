//
// Created by Karla Angélica Peña Guerra on 3/27/22.
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

bool isEmptyList(list l);
void listPrint(list l);
void listPush(list &l, int newData);
void listEnqueue(list &l, int newData);
void listPop(list &l);
void listPopBack(list &l);
node* listFind(list l, int key);
void listDelete(list &l, node* n);
void listDelete(list &l, int key);

int main() {
    list primes{nullptr, nullptr};
    for(int i = 2; i <= 20; i++)
    {
        listEnqueue(primes, i);
    }
    /*
    // We can iterate through the list, knowing how it is made
    node* p = primes.head;
    node* current = nullptr;
    while(p != primes.tail)
    {
        current = p->next;
        while(current != primes.tail->next)
        {
            if(current->data % p->data == 0)
            {
                node* todelete = current;
                current = current->next;
                listDelete(primes, todelete);
            }
            else
            {
                current = current->next;
            }
        }
        p = p->next;
    }
     */
    // here we rely mainly on the functions implemented for the list
    node* p = primes.head;
    while(p != primes.tail)
    {
        int prime = p->data;
        int tailData = primes.tail->data;
        for(int composite = 2 * prime; composite <= tailData; composite += prime)
        {
            listDelete(primes, composite); // if the composite is not in the list, nothing happens
        }
        p = p->next;
    }
    listPrint(primes);

    return 0;
}

// check if the list is empty
bool isEmptyList(list l)
{
    if (l.head == nullptr && l.tail == nullptr)
    {
        return true;
    }
    return false;
}

// print all elements of the list
void listPrint(list l)
{
    if(!isEmptyList(l))
    {
        node* current = l.head;
        while (current != l.tail) {
            cout << current->data << "=> ";
            current = current->next;
        }
        cout << current->data << endl;
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

// insert a new element at the beginning of the list
void listPush(list &l, int newData)
{
    if(isEmptyList(l))
    {
        l.head = new node{newData, nullptr, nullptr};
        l.tail = l.head;
    } else{
        node* newNode = new node{newData, l.head, nullptr};
        l.head->previous = newNode;
        l.head = newNode;
    }
}

// insert a new element at the end of the list
void listEnqueue(list &l, int newData)
{
    if(isEmptyList(l))
    {
        l.head = new node{newData, nullptr, nullptr};
        l.tail = l.head;
    } else {
        node* newNode = new node{newData, nullptr, l.tail};
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

// remove the element at the beginning of the list
void listPop(list &l)
{
    if(!isEmptyList(l))
    {
        l.head = l.head->next;
        delete l.head->previous;
        l.head->previous = nullptr;
    }
}

// remove the last element of the list
void listPopBack(list &l)
{
    if(!isEmptyList(l))
    {
        l.tail = l.tail->previous;
        delete l.tail->next;
        l.tail->next = nullptr;
    }
}

// return a pointer to the first occurence of key in the list
node* listFind(list l, int key)
{
    if(!isEmptyList(l))
    {
        node* current = l.head;
        while(current != nullptr && current->data != key) // make sure current is not null before accessing its data
        {
            current = current->next;
        }
        return current; // will return nullptr if the int does not exist in the list
    }
    return nullptr; // if empty
}

// delete the node n from the list
void listDelete(list &l, node* n)
{
    if(!isEmptyList(l) && n != nullptr)
    {
        if (n == l.head)
        {
            listPop(l);
            return;
        }
        if(n == l.tail)
        {
            listPopBack(l);
            return;
        }
        n->previous->next = n->next;
        n->next->previous = n->previous;
        delete n;
    }
}

// find the first node in the list with data=key and delete it
void listDelete(list &l, int key)
{
    node* n = listFind(l, key);
    listDelete(l, n); // if n is nullptr, nothing happens
}

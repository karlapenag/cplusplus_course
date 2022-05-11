//
// Created by Karla Angélica Peña Guerra on 3/13/22.
//
#include <iostream>
using namespace std;

struct List
{
    int number;
    List* next;
};
List* head = new List;

void l_add(List*& head, // passing in head. Easier to track
           int n)
{
    List** temp = &head; // head is a next pointer with a different name
    // hiding it behind another pointer allows us to treat
    // it like a next
    // temp is now a pointer to next pointers. We can add directly to the
    // last nodes's next pointer and also use it to access the current
    // pointer if we need to
    (*temp) = new List {2, nullptr}; // 2 is only even prime
    temp = &(*temp)->next;
    for (int i = 3; i <= n; i+=2) // start at 3 and only add odd numbers
    {
        (*temp) = new List {i, nullptr};
        temp = &(*temp)->next; // Advance to next node
    }
}

void l_print(List* head){
    List* temp = head;
    while (temp->next != 0)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}

void l_delete(List * head)
{
    List* last = head->next; // track the last known prime node. skip node 2.
    // note this will blow up if there is no node 2.
    while (last) // for every node still in the list
    {
        List** current = &last->next; // similar to trick above.
        // if we have a pointer to the next to be
        // updated, we don't need to track the previous node
        while ((*current)) // look at every node after the last prime
        {
            if ((*current)->number % last->number == 0) // if it's a multiple, remove it.
            {
                List * to_del = (*current); //save node to delete
                (*current) = (*current)->next; // link previous node to next node.
                // effectively automatically advances the node
                delete to_del;
            }
            else // proceed to next node
            {
                current = &(*current)->next;
            }
        }
        last = last->next; // advance to next prime number
    }
}

int main()
{
    int n;
    cout << "Enter up to which number to find prime numbers using Sieve of Eratosthenes: " << endl;
    if (cin >> n)
    {
        // should be a bit more logic here to automatically handle ns of 1 or 2
        List* head = nullptr; // not using a sentinel node
        l_add(head, n); // passing in head rather than global variable free-for-all
        l_delete(head);
        l_print(head);
        return 0;
    }
    else
    {
        cout << "invalid input." << endl;
        return 1;
    }
}




//
// Created by Karla Angélica Peña Guerra on 3/25/22.
//
#include <iostream>
#include <fstream>
using namespace std;


enum blockStatus {
    FREE,
    USED
};

// linked list node to store information about a memory block
struct block {
    int id;
    int size;
    blockStatus status;
    block *next;
    block *previous;
};
block* memoryBlock;
// linked list handle to the whole memory map
struct memorymap { // dynamic memory allocation for linked list
    block* head;
    //block* tail;  // this is optional as it won't help much
};
memorymap memoryMap;

// constants definitions
const long HEAP_SIZE = 1048576; // 1 megabytes

char * memoryArray[HEAP_SIZE] = {nullptr}; // array with memory from the free-store (heap)

// Allocation functions
char * allocateMemory(int size);
void freeMemory(char * pointer);

// suggested memory management functions, feel free to modify prototypes as needed
void insertBlock(memorymap &memMap, int id, int size, blockStatus status);
// the above function should allow to insert a block into the list, respecting the sorting of id's
void mergeFreeBlocks(memorymap memMap);
// the prototype of the above function can be modified to provide specific node(s) as parameters
void printBlocks(memorymap memMap, ofstream &out);
// this function takes as parameter an output stream (open file) and appends to it the status of the memory
// it is supposedly called after each allocation/deallocation


int main() {
    char* A1 = allocateMemory(5);
    char* A2 = allocateMemory(10);
    char* A3 = allocateMemory(7);
    char* A4 = allocateMemory(8);

    printf("Address is %p\n",(void *)A1);
    printf("Address is %p\n",(void *)A2);
    printf("Address is %p\n",(void *)A3);
    printf("Address is %p\n",(void *)A4);

    return 0;
}
void insertBlock(memorymap &memMap, int id, int size, blockStatus status) {
    block *newNode = new block();
    newNode->id = id;
    newNode->size = size;
    if (memMap.head == nullptr) {
        memMap.head = newNode;
        memMap.head->next = nullptr;
        memMap.head->previous = nullptr;
        memMap.head->id = 0;
        memMap.head->status = status;
        return;
    }
    block *traveller = memMap.head;
    while (traveller = nullptr) {
        traveller->id = traveller->id + 1;
        traveller = traveller->next;
    }

    newNode->next = traveller->next;
    newNode->id = traveller->id;

    traveller->next=newNode->previous;
}

char * allocateMemory(int size) { // returns pointer address of a range of char of requested size
    block* newNode = new block;
    newNode->next=NULL;
    newNode->previous=NULL;
    // error if negative number
    while (memoryMap.head==nullptr){
        memoryMap.head=newNode;
        memoryMap.head->id=0;
        return memoryArray;
    }
    //keep track of the current address
    char* current_address=memoryArray;
    int counter;
    int newID=0;
    //add new blocks with the allocated size if list not empty
    for (counter=0; counter<size;counter++){
        current_address++;
        newID+=1;
    }
    newNode->id=newID;
    newNode->status=USED;

    return current_address;
}


void freeMemory(char * pointer) {

}


// the above function should allow to insert a block into the list, respecting the sorting of id's
void mergeFreeBlocks(memorymap memMap){

}
// the prototype of the above function can be modified to provide specific node(s) as parameters
void printBlocks(memorymap memMap, ofstream &out){

}
// this function takes as parameter an output stream (open file) and appends to it the status of the memory
// it is supposedly called after each allocation/deallocation

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
memorymap* memoryMap;

// constants definitions
const long HEAP_SIZE = 1048576; // 1 megabytes

// Allocation functions
char * memoryArray[HEAP_SIZE] = {nullptr}; // array with memory from the free-store (heap)
char * allocateMemory(int size) { // returns pointer address of a range of char of requested size
    char * ptr =nullptr;
    ptr = new char;
    *ptr =
    return
}

}

void freeMemory(char * pointer) {

}

// suggested memory management functions, feel free to modify prototypes as needed
void insertBlock(memorymap &memMap, int id, int size, blockStatus status){

}
// the above function should allow to insert a block into the list, respecting the sorting of id's
void mergeFreeBlocks(memorymap memMap){

}
// the prototype of the above function can be modified to provide specific node(s) as parameters
void printBlocks(memorymap memMap, ofstream &out){
    ofstream outfile("output.txt");
    outfile
            << right
            << setw(10)
            << "ID |"
            << right
            << setw(5)
            << "Size |"
            << right
            << setw(8)
            << "Status"
            << endl;
    for (int i = 0; i < 4; i++)
    {
        cout
                << left
                << setw(10)
                << memoryBlock[i].id
                << left
                << setw(5)
                << memoryBlock[i].size
                << left
                << setw(8)
                << memoryBlock[i].status
                << endl;
    }
    outfile.close();
}
// this function takes as parameter an output stream (open file) and appends to it the status of the memory
// it is supposedly called after each allocation/deallocation
int main() {
    ifstream infile("input.txt");
    string text;
    int number_of_pointers;
    if (infile.fail()) {
        cout << "Input text file does not exist" << endl;
    } else {
        getline(infile, text);
        number_of_pointers = stoi(text);
        cout <<"this is number of pointers : "<< number_of_pointers << endl;
        string *arrays = new string[number_of_pointers];
        while (!infile.eof()) {
            getline(infile, text);
            string action;
            string index;
            string size;
            int counter=0;

            action=text[0];
            text.erase(0,1);
            if (action=="a") {
                for (auto x:text){
                    if (isspace(x)==0){
                        break;
                    }
                    else {counter+=1;}
                }
                text.erase(0,counter);
                counter=0;
                for (auto x:text){
                    if (isspace(x)==0){
                        index+=x;
                        counter+=1;
                    }
                    else{break;}
                }
                memoryBlock->id=stoi(index);
                text.erase(0,counter);
                counter=0;
                for (auto x:text){
                    if (isspace(x)==0){
                        break;
                    }
                    else {counter+=1;}
                }
                text.erase(0,counter);
                for (auto x:text){
                    if (isspace(x)==0){
                        size+=x;
                    }
                    else{break;}
                }
                memoryBlock->size=stoi(size);
                char* arrays[number_of_pointers] = allocateMemory(memoryBlock->size);
            }
            else if (action == "d"){
                for (auto x:text){
                    if (isspace(x)==0){
                        break;
                    }
                    else {counter+=1;}
                }
                text.erase(0,counter);
                counter=0;
                for (auto x:text){
                    if (isspace(x)==0){
                        index+=x;
                        counter+=1;
                    }
                    else{break;}
                }
                memoryBlock->id=stoi(index);
                freeMemory(memoryArray[memoryBlock->id]);
            }

        }
    }
    infile.close();

    return 0;
    }
    char * A1 = allocateMemory(5);
    char * A2 = allocateMemory(10);
    char* A3 = allocateMemory(7);
    char* A4 = allocateMemory(8);
    A4 = allocateMemory(12);
//
// Created by Karla Angélica Peña Guerra on 3/21/22.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

enum blockStatus {
    FREE,
    USED
};

// A linked list node
struct block{
    int id;
    int size;
    blockStatus status;
    block* next;
    block* prev;
};

// constants definitions
const long HEAP_SIZE = 1048576; // 1 megabytes

char memoryArray[HEAP_SIZE] = {0}; // array with memory from the free-store (heap) to allocate
map<int, int> sizesArray;

block* head = nullptr; // linked list to handle the whole memorymap

// Allocation functions
tuple<int,int> allocateMemory(int size, int id);
void freeMemory(char * pointer);

// suggested memory management functions, feel free to modify prototypes as needed
void insertBlock(block** head_ref, int id, int size, blockStatus status);
// the above function should allow to insert a block into the list, respecting the sorting of id's
void mergeFreeBlocks(block** head_ref);
// the prototype of the above function can be modified to provide specific node(s) as parameters
void printBlocks(block** head_ref, ofstream &out);
// this function takes as parameter an output stream (open file) and appends to it the status of the memory
// it is supposedly called after each allocation/deallocation

int main(){
    string text;
    string action;
    string index_str;
    string size_str;
    // int number_of_pointers;
    ifstream infile("input.txt");

    if (infile.fail()) {
        cout << "Input text file does not exist" << endl;
    } else {
        getline(infile, text); // read first line, which refers to the maximum number of pointers needed
        // number_of_pointers = stoi(text);
        // pointersArray = new char[number_of_pointers];
        // cout <<"this is number of pointers : "<< number_of_pointers << endl;
        while (!infile.eof()) { // reading file until the end of line (starting from second line)
            getline(infile, text);
            int counter=0;
            action = text[0]; // the action 'a' or 'd' y in the first position of the line
            text.erase(0,1); // erase the action from string 'text' after storing it in variable

            if (action=="a") {  //if allocate
                for (auto x:text){ // read char by char in string 'text'
                    if (isspace(x)==0){ // if its a character different from a whitespace char (\r,\n,\t,' '), break
                        break;
                    }
                    else {counter+=1;} // if its a whitespace char the return value will be !=0, add to the counter
                    // which reads the number of white spaces
                }
                text.erase(0,counter); //delete whitespaces from 'text'
                counter=0; // reset counter
                for (auto x:text){ // read char by char in string 'text', the first value will be
                    // the character of interest
                    if (isspace(x)==0){ // if its a character different from a whitespace char
                        index_str+=x; // append it to 'index' string
                        counter+=1; //add to the counter which now reads the number of digits of 'index'
                    }
                    else{break;} // if its a whitespace char break
                }
                text.erase(0,counter); // erase the 'index'
                counter=0; //reset counter
                for (auto x:text){// read char by char in string 'text', the first value will be
                    // the white space char
                    if (isspace(x)==0){ // if its char of interest (not whitespace), break
                        break;
                    }
                    else {counter+=1;} // if whitespace add to counter storing number of spaces
                }
                text.erase(0,counter); //erase spaces
                for (auto x:text){// read char by char in string 'text', the first value will be
                    // char of interest
                    if (isspace(x)==0){  // if its a character different from a whitespace char its now the size
                        size_str+=x; // append it to 'size' string
                    }
                    else{break;} //when reach a whitespace char break
                }
                // change from string to index
                int index = stoi(index_str);
                int mem_size = stoi(size_str);
                ofstream out("output.txt");
                out << action <<"\t"<<index<<"\t"<<mem_size<< endl;
                insertBlock(&head,index, mem_size,USED);
                auto [new_id, mem_left] = allocateMemory(mem_size,index);
                out << new_id <<"\t"<<mem_left<<endl;
            }
            else if (action == "d"){ //if deallocate
                for (auto x:text){ // read char by char in string 'text'
                    //delete spaces
                    if (isspace(x)==0){
                        break;
                    }
                    else {counter+=1;}
                }
                text.erase(0,counter); //erase spaces
                counter=0;
                // get index
                for (auto x:text){
                    if (isspace(x)==0){
                        index_str+=x;
                        counter+=1;
                    }
                    else{break;}
                }
                int index = stoi(index_str);
                insertBlock(&head,index,0,FREE);
                ofstream out("output.txt");
                out << action <<"\t"<<index<< endl;
                // freeMemory()
                // mergeFreeBlocks()
            }
            ofstream out("output.txt");
            printBlocks(&head, out);
        }
    }
    infile.close();

    return 0;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void insertBlock(block** head_ref, int id, int size, blockStatus status){
    /* 1. allocate node */
    block *new_node;
    new_node = new block();
    block* last = *head_ref; // used in step 5*/

    /* 2. put in the data */
    new_node->id = id;
    new_node->size = size;
    if (status == FREE){
        new_node->status = FREE;
    }
    if (status == USED){
        new_node->status = USED;
    }

    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = nullptr;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == nullptr)
    {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != nullptr)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;
}

tuple<int,int> allocateMemory(int size, int index) { // returns pointer address of a range of char of requested size
    // char *ptr = memoryArray; // pointer to the first space in array[HEAP_SIZE]
    // char *lastPtr = &memoryArray[HEAP_SIZE-1]; // pointer to the last space in array[HEAP_SIZE]
    int mem_used=0;
    int mem_left=0;
    sizesArray.insert(pair<int, int>(index, size));

    for (auto itr = sizesArray.begin(); itr != sizesArray.end(); ++itr) {
        mem_used=(itr->second)+mem_used;
    }
    mem_left=HEAP_SIZE-mem_used;
    int new_id= (sizesArray[index]-1)+size;

    return {new_id, mem_left};

}

void freeMemory(char * pointer){



}
void mergeFreeBlocks(block** head_ref){
    int point;
    auto prev = sizesArray.find(point+1);
    auto next = sizesArray.find(point-1);

    if (&(prev->second) == 0){
        //merge sizes
        //merge IDs from output
    }
    if (&(next->second)==0){
        //merge sizes
        // merge IDs from output
    }

    vector <int> emptyIDs;
    vector <int> allocatedIDs;

    for (auto& it : sizesArray) {
        // If value is 0 (no memory size allocated) get the key value (ID)
        if (it.second == 0) {
            emptyIDs.push_back(it.first);
        }
    }
    for (auto& it : sizesArray) {
        // If value is 0 (no memory size allocated) get the key value (ID)
        if (it.second != 0) {
            allocatedIDs.push_back(it.first);
        }
    }
    /*if (sizesArray.empty()) {
        sizesArray.insert(
                //pair<int, int>(0, size)); // store index and sizes to calculate free space and identify free spaces
    }else{
        int prev_size= sizesArray[index-1];
        sizesArray.insert(
                //pair<int, int>(new_id, size));
    }*/
}

// This function prints contents of
// linked list starting from the given node
void printBlocks(block** head_ref, ofstream &out){
    out << "ID\tSIZES\tSTATUS\r";
    for (auto itr = sizesArray.begin(); itr != sizesArray.end(); ++itr) {
        out << itr->first
             << '\t' << itr->second << '\n';
    }
    out.close();
}





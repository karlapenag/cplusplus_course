//
// Created by Karla Angélica Peña Guerra on 3/27/22.
//
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    const long HEAP_SIZE = 1048576; // 1 megabytes
    char memoryArray[HEAP_SIZE]{0}; // array with memory from the free-store (heap) to allocate
    cout<<"number"<<endl;
    int value;
    cin>>value;
    char *pointersArray[20];
    char *ptr = memoryArray; // pointer to the first space in array[HEAP_SIZE]
    char *lastPtr = &memoryArray[HEAP_SIZE-1]; // pointer to the last space in array[HEAP_SIZE]
    pointersArray[0] = ptr+20;
    map<int, int> sizesArray;
    sizesArray.insert(pair<int, int>(0, 42));
    sizesArray.insert(pair<int, int>(1, 2084));
    sizesArray.insert(pair<int, int>(2, 2239));
    }else{
        int prev_size= sizesArray[index-1];
        int new_id=prev_id+prev_size;
        sizesArray.insert(
                pair<int, int>(new_id, size));
    }
}

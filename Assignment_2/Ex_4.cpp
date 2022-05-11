//
// Created by Karla Angélica Peña Guerra on 2/27/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

struct adjList {
    string label;
    int adjVertices;
    string *arrayVertices;
};

int main(){
    adjList* arrayVertex; // define structure

    cout << " EXERCISE 4 " << endl;
    cout << " This program prints-out the adjacency list of a vertices in a graph." << endl;
    cout << "How many vertices in the graph: ";
    int numVertices = 0;
    cin >> numVertices;

    arrayVertex = new adjList[numVertices];  // dynamic array to store structures with assigned
    for (int i = 0; i < numVertices; i++){  // for loop to prompt and store each of the vertices and their edges.
        cout << "Vertex " << i + 1 << ": " <<endl;
        cout << "- label: ";
        string labelVertex="";
        cin >> labelVertex;

        cout << "- number of adjacent vertices: ";
        int adjVertices = 0;
        cin >> adjVertices;   // number of adjacent vertices

        string *arrayVertices;
        arrayVertices = new string[adjVertices];  // dynamic array to store adjacent vertices labels
        string adjVertex;

        for (int x =0; x < adjVertices; x++){
            cout << "Adjacent vertex label " << x + 1 << ": ";
            cin >> adjVertex;

            arrayVertices[x] = adjVertex; // add labels to dynamic array for each Vertex
        }
        arrayVertex[i].label = labelVertex;
        arrayVertex[i].adjVertices = adjVertices;
        arrayVertex[i].arrayVertices = arrayVertices;
    }

    // graph adjacent vertices list
    cout<<"======================================"<<endl;
    for (int i = 0; i < numVertices; i++){  // loop into each structure inside the array
        cout << arrayVertex[i].label;
        int num = arrayVertex[i].adjVertices;
        for (int x = 0; x < num; x++) {   // loop into each adjacent vertex inside the structure
            cout << " ->" << arrayVertex[i].arrayVertices[x];
        }
        cout << endl;
    }
    return 0;
}

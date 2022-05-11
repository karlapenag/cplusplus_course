//
// Created by Karla Angélica Peña Guerra on 2/22/22.
//
// CS 207
// 180951
#include <iostream>
using namespace std;

void addAdjacency(string adj[], int u, string adjVertex)
// simple function to concatenate the adjacency vertices as a string inside the array
{
    adj[u] += adjVertex;
}

void graph(string adj[], int V)  // function to print the graph with the list of adjacent vertices for each vertex
{
    cout<<"======================================"<<endl;
    for (int v = 0; v < V; ++v) {
        string adjList = adj[v]; //copy the content of the Vertex & its adjacency vertices to another string
        cout << adjList[0]; // print only the character in position 0 of the new string (the Vertex label).
        adjList = adjList.erase(0,1); // erase the Vertex label from the new string (now it only has the adjacency vertices)
        for (auto x : adjList) // for loop to print each adjacency vertex
            cout << " ->" << x;
        cout <<endl;
    }
}

int main()
{
    cout << " EXERCISE 4 " << endl;
    cout << " This program prints-out the adjacency list of a vertices in a graph." << endl;
    cout << "How many vertices in the graph: ";
    int numVertex = 0;
    cin >> numVertex;
    string adj[numVertex]; // initialize array list 'adj' of adjacency vertices.
    int runs = numVertex + 1; // times the following for loop has to run
    // (as vertices count will start in 1, a +1 has to be added for the running loops to be complete).
    for (int i = 1; i < runs; i++){  // for loop to prompt and store each of the vertices.
        cout << "Vertex " << i << ": " <<endl;
        cout << "- label: ";
        string labelVertex="";
        cin >> labelVertex;
        cout << "- number of adjacent vertices: ";
        int adjVertices = 0;
        cin >> adjVertices;


        adj[i-1] = labelVertex; // the list of adjacency vertices starts in position i-1 (0) and is equal to the prompted string label.
        // Will keep track of all the first prompted Vertex labels.
        string adjVertex;
        for (int x = 0; x < adjVertices; x++){ // for loop to prompt and add the edges for each vertex to the array list.
            int vertIndex= x+1;
            cout<<"Adjacent vertex label "<<vertIndex<<": ";
            cin>>adjVertex;

            addAdjacency(adj, i-1, adjVertex);  // i-1 for it to be in the same position as the prompted Vertex label.
        }
    }
    graph(adj, numVertex); // call the graph function to print the array list.
    // The array length is the total of Vertex labels prompted (numVertex).
    return 0;
}



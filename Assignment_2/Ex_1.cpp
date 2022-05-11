//
// Created by Karla Angélica Peña Guerra on 2/22/22.
//
// CS 207
// 180951
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    cout << " EXERCISE 1 " << endl;
    cout << " This program displays an array of integers to represent a minesweeper grid of 25 by 25"
         << endl;
    int myArray[27][27] = {0}; // 2 more lines added to rows and columns to create fictive lines around grid
    srand (10); // set to seed the pseudo-random number generator (this will always use the same random numbers; comment line to generate different)
    for (int x = 1 ; x < 26; x++){
        for (int y = 1; y < 26; y++){
            // int randNum = {rand()%1000}; // random number from 0 to 999
            int randNum = {rand()}; // random number with no range restriction
            if (randNum % 5 == 0){ // if multiple of 5
                myArray[x][y]= -1; // assign a -1 value (mine)
            }
            // cout << myArray[x][y] << " ";   // UN-COMMENT TO PRINT THE GRID WITH THE 0's AND -1's.
        }
        // cout << endl;                      //  UN-COMMENT TO PRINT THE GRID WITH THE 0's AND -1's.
    }
    cout << "Minesweeper grid: "<< endl;

    int sum = 0;
    for (int x = 1; x < 26; x++){   //   to move in the x axis of the array
        for (int y = 1; y < 26; y++){   // to move in the y axis of the array
            if (myArray[x][y] >- 1){ // for all the positions where there is a mine
                for (int x2 = -1; x2 < 2; x2++){  // to move in the x axis in a window of -1 to -1 of the current position
                    for (int y2 = -1; y2 < 2; y2++){ // to move in the y axis in a window of -1 to +1 of the current position
                        sum += abs(myArray[x + x2][y + y2]); // sum all the 8 surrounding cells content. The sum of the mines (-1's)
                        // will give the total number of mines around the current position in negative. 'Abs' to make it positive.
                    }
                }
                cout << sum <<" ";
                sum = 0;   // reset sum for each cell
            }
            else{
                cout<<"* ";  // if the cell content is < 0, there is a mine (*)
            }
        }
    cout<<endl; // print a tab after moving rows
    }
    return 0;
}

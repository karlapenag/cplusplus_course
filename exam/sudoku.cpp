//
// Created by Karla Angélica Peña Guerra on 3/27/22.
// debugged
#include <iostream>
using namespace std;

bool isRowValid(int grid[9][9], int rowIndex);
bool isColumnValid(int grid[9][9], int colIndex);
bool isBoxValid(int grid[9][9], int boxIndex);

int main() {
    int sudokuGrid[9][9] = {9, 5, 7, 6, 1, 3, 2, 8, 4,
                            4, 8, 3, 2, 5, 7, 1, 9, 6,
                            6, 1, 0, 8, 4, 9, 5, 3, 7,
                            1, 7, 8, 0, 6, 4, 9, 5, 2,
                            5, 2, 4, 9, 7, 1, 3, 6, 8,
                            3, 6, 9, 5, 2, 8, 7, 4, 1,
                            8, 0, 5, 7, 9, 2, 6, 1, 3,
                            2, 9, 1, 4, 3, 0, 8, 7, 5,
                            7, 3, 6, 0, 8, 5, 4, 2, 9};

    bool boolArray[3][9]={true}; // array to store bool returns from functions for specific row/column/box
    // false meaning there are no duplicates of numbers in row/column/box

    for (int i=0;i<9;i++) {
        boolArray[0][i]=isRowValid(sudokuGrid,i);
        boolArray[1][i]=isColumnValid(sudokuGrid,i);
        boolArray[2][i]=isBoxValid(sudokuGrid,i);
    }

    // look for any false in each row/column/box
    bool rowValid = (end(boolArray[0]) == find(begin(boolArray[0]),
                                               end(boolArray[0]),
                                               false) );
    bool columnValid = (end(boolArray[1]) == find(begin(boolArray[1]),
                                                  end(boolArray[1]),
                                                  false) );
    bool boxValid = (end(boolArray[2]) == find(begin(boolArray[2]),
                                               end(boolArray[2]),
                                               false) );
    // cout<<rowValid<<endl;
    // cout<<columnValid<<endl;
    // cout<<boxValid<<endl;
    // if all false grid is Valid
   bool gridValid = true;
   if (!rowValid || !columnValid || !boxValid){
       gridValid = false;
   }
   else{gridValid = true;}

    // insert a snippet here to check that all rows, columns and boxes are valid

    if(gridValid)
    {
        cout << "This is a correct Sudoku grid." << endl;
    }
    else
    {
        cout << "There is a problem with this Sudoku grid." << endl;
    }
    return 0;
}

bool isRowValid(int grid[9][9], int rowIndex)
{
    string copy="";
    string appended="";
    for (int c=0;c<9;c++) { //iterate through columns in same row (rowIndex)
        appended += std::to_string(grid[rowIndex][c]);
    }
    // cout<<"appended row "<<appended<<endl;
    for (int i=0;i<9;i++){
        copy=appended;
        copy.erase(i,1); // remove the value that is going to be evaluated
        if (copy.find(std::to_string(grid[rowIndex][i])) != string::npos){ // find duplicates of the number in index inside the row string
            return false; // the number is already in the row
        }
    }
    return true;
}


bool isColumnValid(int grid[9][9], int colIndex)
{
    string copy="";
    string appended="";
    for (int r=0;r<9;r++){ //iterate through columns in same row
        appended+=std::to_string(grid[r][colIndex]);
    }
    // cout<<"appended column "<<appended<<endl;
    for (int i=0;i<9;i++){
        copy=appended;
        copy.erase(i,1); // remove the value that is going to be evaluated
        if (copy.find(std::to_string(grid[i][colIndex])) != string::npos){ // find duplicates of the number in index inside the column string
            return false; // the number is already in the column
        }
    }
    return true;
}

bool isBoxValid(int grid[9][9], int boxIndex)
{
    string copy="";
    string appended="";
    int count=0;   // index for number in box string for erase in copy
    // for boxIndex=0,1,2 : rows: 0,1,2 & iterate through columns: boxIndex*3
    // for boxIndex=3,4,5 : rows: 3,4,5 & iterate through columns: (boxIndex-3)*3
    // for boxIndex=6,7,8 : rows: 6,7,8 & iterate through columns: (boxIndex-3)*3

    if (boxIndex==0 || boxIndex==1 || boxIndex==2){
        for (int i=0; i<3;i++){
            for(int j=0; j<3;j++){
                appended+=std::to_string(grid[i][j+(boxIndex*3)]);  // create string with all the values in box
            }
        }
        // cout<<"appended box 1 "<<appended<<endl;
        for (int i=0;i<3;i++){
            for(int j=0; j<3;j++){
                copy=appended;
                copy.erase(count,1);
                if (copy.find(std::to_string(grid[i][j+(boxIndex*3)])) != string::npos){
                    return false;
                }
                ++count;
            }
        }
        return true;
    }
    else if (boxIndex==3 || boxIndex==4 || boxIndex==5){
        for (int i=3; i<6;i++){
            for(int j=0; j<3;j++){
                appended+=std::to_string(grid[i][j+((boxIndex-3)*3)]); // create string with all the values in box
            }
        }
        // cout<<"appended box 2 "<<appended<<endl;
        for (int i=3;i<6;i++){
            for(int j=0; j<3;j++){
                copy=appended;
                copy.erase(count,1);
                if (copy.find(std::to_string(grid[i][j+((boxIndex-3)*3)])) != string::npos){
                    return false;
                }
                ++count;
            }
        }
        return true;
    }
    else if (boxIndex==6 || boxIndex==7 || boxIndex==8){
        for (int i=6; i<9;i++){
            for(int j=0; j<3;j++){
                appended+=std::to_string(grid[i][j+((boxIndex-6)*3)]); // create string with all the values in box
            }
        }
        // cout<<"appended box 3 "<<appended<<endl;
        for (int i=6;i<9;i++){
            for(int j=0; j<3;j++){
                copy=appended;
                copy.erase(count,1);
                if (copy.find(std::to_string(grid[i][j+((boxIndex-6)*3)])) != string::npos){
                    return false;
                }
                ++count;
            }
        }
        return true;
    }
    // the boxes are indexed in a row-wise fashion such that
    // the top-left box has index 0
}
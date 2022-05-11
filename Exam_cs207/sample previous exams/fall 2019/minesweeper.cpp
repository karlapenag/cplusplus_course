/*******************************************************************************
**** minesweeper.cpp
****
**** This is an implementation of a console based minesweeper game.
**** You are required to implement the two functions that are missing.
****
****
**** Author: Malek Smaoui
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX_WIDTH = 25;	// maximum width of a mine field (nbr of cells)
const int MAX_HEIGHT = 25;	// maximum height of a mine field (nbr of cells)
const double MINE_DENSITY = 0.1; 	// the number of mines is the density
                                    // multiplied by the total number of cells in the mine field


struct cell {
	int value;      // -1 if a mine, between 0 and 8 if it is not
	bool visible; // whether the player has stepped on that cell
	bool marked;	// whether the player thinks this is a mine
};


// return_type generateMineField(parameters);
void getCoordinates(int &row, int &column, int height, int width, char command);
bool revealCell(cell** mineField, int height, int width, int row, int column);
void displayMineField(cell ** mineField, int height, int width);
bool mineFieldCleared(cell **mineFiled, int height, int width);

/************ main function ***********
**** Implements game interface and tests success or failure of the player
***************************************/
int main()
{
	int width = -1;
	int height = -1;
	int nbrMines = -1;
	int nbrMarkedMines = 0;
	int row = -1;
	int column = -1;
	char command;
	bool gameOn = true;

    srand(1);
	cout << "This is the minesweeper game.\n\n" << endl;

    // generating the minefield
	//call to generateMineField with appropriate arguments

	// displaying the minefield
	displayMineField(mineField, height, width);

    // playing the game
	/*while(true)
	{
		cout << "You have " << nbrMines-nbrMarkedMines << " mines left to find. ";
		cout << "Please enter:" << endl;
		cout << "- 'S' if you'd like to step on a cell." << endl;
		cout << "- 'M' if you'd like to mark a cell as a mine. " << endl ;
		cout << "- 'U' if you'd like to unmark a cell already marked as a mine."<< endl;
		cout << "- 'E' if you'd like to exit the game." << endl << endl;
		cout << " >  ";
		cin >> command;
		while(command != 'M' && command != 'm' && command != 'S' && command != 's'
						&& command != 'E' && command != 'e' && command != 'U' && command != 'u')
		{
			cout << "Wrong entry." << endl;
			cout << "You have " << nbrMines-nbrMarkedMines << " mines left to find. ";
			cout << "Please enter:" << endl;
			cout << "- 'S' if you'd like to step on a cell." << endl;
			cout << "- 'M' if you'd like to mark a cell as a mine. " << endl;
			cout << "- 'U' if you'd like to unmark a cell already marked as a mine."<< endl;
			cout << "- 'E' if you'd like to exit the game."<< endl << endl;
			cout << " >  ";
			cin >> command;
		}

		if (command == 'E' || command == 'e')
		{
			cout << "Good bye! Come back!" << endl;
			return 0;
		}
		else
		{
			getCoordinates(row, column, height, width, command);

			if(command == 'M' || command == 'm')
			{
				if(mineField[row][column].visible || mineField[row][column].marked)
					cout << "\nCan not mark a cleared or marked cell\n" << endl;
				else
				{
					mineField[row][column].marked = true;
					nbrMarkedMines++;
					displayMineField(mineField, height, width);
					if(nbrMarkedMines == nbrMines)
					{
						cout << "\nYou marked all mines, would you like to check your solution ? y/n > " << endl;
						cin >> command;
						if(command == 'y' || command == 'Y')
						{
							if(mineFieldCleared(mineField, height, width))
							{
								displayMineField(mineField, height, width);
								cout << "\nCongratulations! You secured all mines.\n" << endl;
								return 0;
							}
							else
							{
								for(int i = 0; i < height; i++)
									for(int j = 0; j < width; j++)
										mineField[i][j].visible = true;
								displayMineField(mineField, height, width);
								cout << "\nBoooooooooom! \n\n\n GAME OVER\n";
				  			return 0;
							}
						}
					}
				}
			}
			else if(command == 'U' || command == 'u')
			{
				if(!mineField[row][column].marked)
					cout << "\nCannot unmark a cell that is not already marked\n" << endl;
				else
				{
					mineField[row][column].marked = false;
					nbrMarkedMines--;
					displayMineField(mineField, height, width);
				}
			}
			else // cammand == 's' or 'S'
			{
				gameOn = revealCell(mineField, height, width, row, column);
				displayMineField(mineField, height, width);
				if(gameOn == false)
				{
					cout << "\nBoooooooooom! \n\n\n GAME OVER\n";
				  return 0;
				}
			}
		}
		if(mineFieldCleared(mineField, height, width))
		{
			cout << "\nCongratulations! You secured all mines.\n" << endl;
			return 0;
		}
	}*/
	return 0;
}

/***********generateMineField **********
**** Given the size of the mine field and the number of mines
**** the functions chooses random locations for mines, fill the corresponding
**** cells with special values, fills the rest of the cells with values
**** corresponding to the number of mines in their 8-cell neighborhood
*****************************************/
// return_type generateMineField(parameters)
{

}

/********* getCoordinates ***********************
**** Prompts the player and reads in for a cell coordinates
**** according to the action he would like to perform.
************************************************/
void getCoordinates(int &row, int &column, int height, int width, char command)
{
	switch (command)
	{
		case 'm': case 'M':
			cout << "\nPlease enter the coordinates of the cell you would like to mark as a mine.\n\n";
			break;
			case 'u': case 'U':
			cout << "\nPlease enter the coordinates of the cell you would like to unmark.\n\n";
			break;
		case 's': case 'S':
			cout << "\nPlease enter the coordinates of the cell you would like to step on.\n\n" ;
			break;
		default:
			return;
	}

	cout << "row\t = " ;
	cin >> row;
	while (row <= 0 || row > height)
	{
		cout << "Value out of range. Please enter the row number again." << endl;
		cout << "row\t = ";
		cin >> row;
	}
	row--;
	cout << "column\t = " ;
	cin >> column;
	while (column <= 0 || column > width)
	{
		cout << "Value out of range. Please enter the column number again." << endl;
		cout << "column\t = ";
		cin >> column;
	}
	column--;

	return;
}


/*******diplayMineField ************
**** displays cell value if cell have been revealed.
**** M if cell have been marked as a mine
**** empty box if cell is still invisible
***********************************/
void displayMineField(cell** mineField, int height, int width)
{
	cout << endl << endl;
	cout << setw(2) << ' ';
	for (int j = 0; j < width; j++)
    cout << setw(3) << j+1;
  cout << endl;
	for (int i = 0; i < height; i++)
	{
		cout << setw(2) << ' ';
		for (int j = 0; j < width; j++)
        cout << "+--";
    cout << "+" << endl;
    cout << setw(2) << i+1;
    for (int j = 0; j < width; j++)
    {
    	if(!mineField[i][j].visible && mineField[i][j].marked)
    		cout << "|" << setw(2) << 'M';
    	if(!mineField[i][j].visible && !mineField[i][j].marked)
    		cout << "|" << setw(2) << ' ';
			if(mineField[i][j].visible && mineField[i][j].value != -1)
				cout << "|" << setw(2) << mineField[i][j].value;
			if(mineField[i][j].visible && mineField[i][j].value == -1)
				cout << "|" << setw(2) << '*';

    }
    cout << "|" << endl;
  }
    cout << setw(2) << ' ';
		for (int j = 0; j < width; j++)
        cout << "+--";
    cout << "+" << endl;
    cout << endl;
}

/*******revealCell*********
**** renders part of the mine field visible
**** according to the value of the cell  stepped on
**** returns whether stepped on mine or not
*****************************/
bool revealCell(cell** mineField, int height, int width, int row, int column)
{
	if(mineField[row][column].value == -1)
	{
		for(int i = 0; i < height; i++)
			for(int j = 0; j < width; j++)
			{
				mineField[i][j].visible = true;
			}
		return false;
	}

	if(mineField[row][column].value > 0)
	{
		mineField[row][column].visible = true;
	}

	if(mineField[row][column].value == 0 && mineField[row][column].visible == false)
	{
		mineField[row][column].visible = true;
		if(row > 0)
		{
			revealCell(mineField, height, width, row-1, column);
			if(column > 0)
				revealCell(mineField, height, width, row-1, column-1);
			if(column < width - 1)
				revealCell(mineField, height, width, row-1, column+1);
		}
		if(row < height - 1)
		{
			revealCell(mineField, height, width, row+1, column);
			if(column > 0)
				revealCell(mineField, height, width, row+1, column-1);
			if(column < width - 1)
				revealCell(mineField, height, width, row+1, column+1);
		}
		if(column > 0)
			revealCell(mineField, height, width, row, column-1);
		if(column < width - 1)
			revealCell(mineField, height, width, row, column+1);
	}
	return true;
}
/****** mineFieldCleared *******
**** Checks whether all mnes have been correctly identified
**** in that case it will reveal the whole field
********************************/
bool mineFieldCleared(cell **mineField, int height, int width)
{
	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
		{
			if(mineField[i][j].value == -1 && !mineField[i][j].marked)
				return false;
		}

	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
			mineField[i][j].visible = true;

	return true;
}



/*
 - Patrick Tate
 - HW02
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Matrix.h"
#include <ctime>
#include <cstdlib>
using namespace std;

//defualt constructor
Matrix::Matrix(){
    std::vector<std::vector<int> > grid;
    rows = 0;
    columns = 0;
}

//obtain row size and column size from user, then fill that object's grid with 0's
void Matrix::fillGrids(Matrix& obj){
    
    unsigned int rows, columns;
    
    cout << "Enter how many rows you want for your grid.\n";
    cin  >> rows;
    cout << "Enter how many columns you want for your grid.\n";
    cin  >> columns;
    
    obj.setRows(rows);
    obj.setColumns(columns);
    
    ////temp vector used to set object's grid
    vector<int> vec(obj.getColumns(), 0);
    vector<vector<int> > tempVec(obj.getRows(), vec);
    
    obj.setGrid(tempVec);
}
//generate a random row
int Matrix::randRows(Matrix obj){
    int randNum = (int)rand()%obj.getRows();
    return randNum;
}

//generate a random column
int Matrix::randCols(Matrix obj){
    int randNum = (int)rand()%obj.getColumns();
    return randNum;
}

//add the necessary amount of 1's to the object's grid
void Matrix::addOnes(Matrix& obj){
    
    //temp vector used to set object's grid
    vector<int> vec(obj.getColumns(), 0);
    vector<vector<int> > tempVec(obj.getRows(), vec);
    
    int onesNeeded;//  1/3 of grid must be filled with 1's
    
    //determine how many 1's are needed depending on whether 3 divides rows*columns evenly
    if (((obj.getRows()*obj.getColumns())%3) == 0) {
        onesNeeded = ((obj.getRows()*obj.getColumns())/3);
    }
    else {
        onesNeeded = ((obj.getRows()*obj.getColumns())/3) + 1;
    }
    
    //fill 1/3 of grid with 1's in random locations
    for (int i = 0; i < onesNeeded; i++) {
        int randRow = randRows(obj);
        int randColumn = randCols(obj);
        //if grid position already has a randomly placed 1, repeat function until correct amount 1's get placed
        if (tempVec[randRow][randColumn] == 0) {
            tempVec[randRow][randColumn] = 1;
        }
        else
            --i;
    }//for
      
        //set object's grid to the temp vector with 0's and random 1's
        obj.setGrid(tempVec);
}

//compares two oject's grids, if there is a 1 in both grid's location, a 1 is added in that location
//to a third grid
void Matrix::compareVec(Matrix obj1, Matrix obj2){
    
    //grids must have same number of rows and same number of columns to be compared
    if ((obj1.getRows() != obj2.getRows()) || (obj1.getColumns() != obj2.getColumns())) {
        cout << "Sorry, your grids must have the same parameters. Try again.\n";
        exit(0);
    }
    //temp vector to hold comparison values
    vector<int> vec(columns, 0);
    vector<vector<int> > grid3(rows, vec);
    
    //compare each element and add a 1 to grid3 if there is a 1 in both grid1 and grid2 locations
    for (int i = 0; i < obj1.getRows(); i++) {
        for (int j = 0; j < obj1.getColumns(); j++) {
            if ((obj1.getGrid()[i][j] == 1) && (obj2.getGrid()[i][j] == 1)) {
                grid3[i][j] = 1;
            }
        }//for
    }//for
    
    //dispaly new vector
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << grid3[i][j];
        }//for
        cout << endl;
    }//for
}

//display grid
void Matrix::displayGrid(Matrix obj){
    for (int i = 0; i <obj.getRows(); i++) {
        for (int j = 0; j < obj.getColumns(); j++) {
            cout << obj.getGrid()[i][j];
        }//for
        cout << endl;
    }//for
}

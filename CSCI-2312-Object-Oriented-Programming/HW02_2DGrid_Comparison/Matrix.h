/*
 - Patrick Tate
 - HW02
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef Matrix_h
#define Matrix_h
#include <vector>
#include <iostream>

class Matrix {
    
private:
    std::vector<std::vector<int> > grid;
    unsigned int rows, columns;
    
public:
    Matrix();
    void setGrid(std::vector<std::vector<int> > _grid) { grid = _grid;}
    void setRows(unsigned int _rows) {rows = _rows;}
    void setColumns(unsigned int _columns) {columns = _columns;}
    std::vector<std::vector<int> > getGrid() const {return grid;}
    unsigned int getRows() const {return rows;}
    unsigned int getColumns() const {return columns;}
    void fillGrids(Matrix& obj);//fill grids with 0's
    void addOnes(Matrix& obj);//fill 1/3 of grid with randomly placed 1's
    int randRows(Matrix obj);//generates a number for a random row
    int randCols(Matrix obj);//generates a number for a random column
    void compareVec(Matrix obj1, Matrix obj2);//compares the grids of two objects
    void displayGrid(Matrix obj);    
};


#endif /* Matrix_h */

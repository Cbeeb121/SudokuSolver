#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
Sudoku(int grid[9][9]);
~Sudoku();
bool recurse(int grid[9][9]);
bool clearPlacement(int grid[9][9], int &row, int &col);
bool placementApproved(int grid[9][9], int row, int col, int num);
bool checkRow(int grid[9][9], int row, int num);
bool checkCol(int grid[9][9], int col, int num);
bool checkSubSquare(int grid[9][9], int givenRow, int givenCol, int num);
void print(int grid[9][9]);

private:
};
#endif

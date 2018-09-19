#include"Sudoku.h"
#include<iostream>

using namespace std;

Sudoku::~Sudoku(){}

Sudoku::Sudoku(int grid[9][9])
{
  if (recurse(grid) == true){print(grid);}
  else
  {
    cout<<"No solutions. Sorry. :["<<endl;
  }
}

bool Sudoku::checkRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col <9; col++){
        if (grid[row][col] == num){return true;}
      }
    return false;
}

bool Sudoku::checkCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row <9; row++){
        if (grid[row][col] == num){return true;}
      }
    return false;
}

bool Sudoku::checkSubSquare(int grid[9][9], int givenRow, int givenCol, int num){
  for (int row = 0; row < 3; row++){
      for (int col = 0; col < 3; col++){
            if (grid[row+givenRow][col+givenCol] == num){return true;}
          }
        }
    return false;
}

bool Sudoku::placementApproved(int grid[9][9], int row, int col, int num)
{
    return (!checkSubSquare(grid, row - row % 3 , col - col % 3, num) &&
            !checkRow(grid, row, num) && !checkCol(grid, col, num));
}

void Sudoku::print(int grid[9][9])
{
  cout << "\nSolved Puzzle:\n------------------\n";
  for (int row=0; row<9; row++){
    for (int col=0; col<9; col++){
      cout<<grid[row][col]<<" ";
      }
    cout<<endl;
}
cout << "------------------\n";
}

bool Sudoku::clearPlacement(int grid[9][9], int &row, int &col)
{
    for (row=0; row<9; row++){
        for (col=0; col<9; col++){
            if (grid[row][col] == 0){return true;}
          }
        }
    return false;
}

bool Sudoku::recurse(int grid[9][9])
{
    int row, col;
    if (!clearPlacement(grid, row, col))
    {
     return true;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (placementApproved(grid, row, col, num))
        {
            grid[row][col] = num;
            if (recurse(grid))
            {
              return true;
            }
          grid[row][col] = 0;
        }
    }
  return false;
}

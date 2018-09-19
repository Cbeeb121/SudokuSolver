#include"Exec.h"
#include"Sudoku.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

Exec::~Exec(){}

Exec::Exec(string filename)
{
  ifstream inFile;
  inFile.open(filename);
  int num = 0;
  inFile >> num;
  for(int i=0; i<num; i++){
  cout << "\nPuzzle " << i+1 << endl;
  cout << "--------\n";
//Temp char array to read in
/*char** temp; //temp char array
temp = new char*[9];
for(int i=0; i<9; i++)
temp[i] = new char[9];*/

//temp char array for read in
char temp[9][9];
//file reading
for(int i=0; i<9; i++){
  for(int j=0; j<9; j++){
    inFile >> temp[i][j];
    if(temp[i][j] == '_'){temp[i][j] = '0';}
  }
}

//turning input into an int array
/*int** arr; //int array
arr = new int*[9];
for (int i=0; i<9; i++){
  arr[i] = new int[9];
}
for(int i=0; i<9; i++){
  for(int j=0; j<9; j++){
    arr[i][j] = temp[i][j] - '0';
  }
}*/

int arr[9][9];
for(int i=0; i<9; i++){
  for(int j=0; j<9; j++){
    arr[i][j] = temp[i][j] - '0';
  }
}

//Printing out old array
cout << "\nOriginal Puzzle:\n------------------\n";
for(int i=0; i<9; i++){
  for(int j=0; j<9; j++){
    cout << arr[i][j] << " ";
  }
  cout << endl;
}
cout << "------------------\n";

Sudoku puzzle(arr);

/*for(int i=0;i<9; i++){delete[] arr[i];}
delete[] arr;*/
  }
}

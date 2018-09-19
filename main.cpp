#include"Exec.h"
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv){

  if(argc < 2)
  {
    cout<<"Must give a file name on command line. (ex. 'input.txt')\n";
  }
  else
  {
  Exec run(argv[1]);
  }
}

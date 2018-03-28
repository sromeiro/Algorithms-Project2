#include<iostream>
#include<stdlib.h>
#include<stdexcept>
#include<string>
#include<fstream>

#define FILENAME "input.txt" //Change file name here if needed.

using namespace std;

int main()
{

  ifstream inFile; //Create the input file object
  inFile.open(FILENAME);

  inFile.close(); //Closes the open input file






  //Successful termination of program
  cout << "Program terminated sucesfully" << endl;
  return 0;
}

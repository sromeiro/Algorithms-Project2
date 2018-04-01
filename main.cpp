#include<iostream>
#include<stdlib.h>
#include<stdexcept>
#include<cmath>
#include<string>
#include<fstream>

#define FILENAME "input.txt" //Change file name here if needed.

using namespace std;

int main()
{
  int iterations; //To retrieve the amount of problems we'll run through
  int n, s, l; //To retrieve the sampler size, small and long parameters
  long updated, current, previous; //To keep track of what's needed for this algo

  ifstream inFile; //Create the input file object
  inFile.open(FILENAME);
  if (!inFile)
  {
    cerr << "Unable to open file";
    exit(1);   // call system to stop
  }

  ofstream outFile; //Create the output file object
  outFile.open("output.txt");
  if (!outFile)
  {
    cerr << "Unable to create file";
    exit(1);   // call system to stop
  }

  inFile >> iterations; //Grab the first number in the text file for iterations
  for(int j = 1; j <= iterations; j++)
  {
    inFile >> n >> s >> l; //Grab sampler size, small and long candy values

    if(n == 1)
    {
      current = pow(s,1); //Initializes previous to s^1
    }

    else if(n == 2)
    {
      current = pow(s,2) + l; //Initializes current to s^2 + l
    }

    else
    {
      previous = pow(s,1); //Initializes previous to s^1
      current = pow(s,2) + l; //Initializes current to s^2 + l

      for(int i = 3; i <= n; i++) //Main algorithm that calculates the final value
      {
        updated = current * s + previous * l;
        previous = current;
        current = updated;
      }
    }
    
    outFile << current << endl; //Writes the final current value to the txt file
  }

  inFile.close(); //Closes the open input file
  outFile.close(); //Closes the open output file

  //Successful termination of program
  cout << "Program terminated sucesfully" << endl;
  return 0;
}

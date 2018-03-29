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

  //=============================TEST CODE====================================//
  /*            UNCOMMENT THIS CODE TO TEST THE WORKIG ALGORITHM
  int n, s, l;
  cout << "Please enter the sampler size: ";
  cin >> n;
  cout << endl << "Please enter the variety of small candies: ";
  cin >> s;
  cout << endl << "Please enter the variety of long candies: ";
  cin >> l;
  cout << endl << "You have entered [" << s << "] small candies, [" << l << "]"
       << " long candies for a sampler of size [" << n << "]" << endl;

  int newValue, current, previous;

  for(int i = 1; i <= n; i++)
  {
    if(i == 1)
    {
      previous = pow(s,i); //Raises base "s" to power of exponent "i"
    }
    else if(i == 2)
    {
      current = pow(s,i) + l; //Calculates s^i + l
    }
    else
    {
      newValue = current * s + previous * l;
      previous = current;
      current = newValue;
    }
  }

  cout << "\nWe have created [" << current << "] samplers, each of size [" << n
       << "], with the provided [" << s << "] small candies and [" << l
       << "] long candies" << endl << endl;
  */
  //==========================================================================//

  int iterations; //To retrieve the amount of problems we'll run through
  int n, s, l; //To retrieve the sampler size, small and long parameters
  int updated, current, previous; //To keep track of what's needed for this algo

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
    previous = pow(s,1); //Initializes previous to s^1
    current = pow(s,2) + l; //Initializes current to s^2 + l

    for(int i = 3; i <= n; i++) //Main algorithm that calculates the final value
    {
      updated = current * s + previous * l;
      previous = current;
      current = updated;
    }

    outFile << current << endl; //Writes the final current value to the txt file
  }

  inFile.close(); //Closes the open input file
  outFile.close(); //Closes the open output file

  //Successful termination of program
  cout << "Program terminated sucesfully" << endl;
  return 0;
}

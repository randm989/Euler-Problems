#include "p11.hpp"
#include "MyMathLib.hpp"
#include <vector>
#include <iostream>
#include <fstream>

//What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 2020 grid?

uint p11::execute() 
{
  std::ifstream myfile;
  myfile.open("../p11.txt");
  std::string s;
  s.assign(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>());
  myfile.close();

  std::vector<std::vector<uint> > grid;
  std::vector<uint> row;
  uint value = 0;

  for ( uint i = 0; i < s.size(); ++i )
  {
    if ( s[i] >= '0' && s[i] <= '9' )
    {
      value *= 10;
      value += s[i] - '0';
    }
    else
    {
      row.push_back(value);

      if ( s[i] == '\n' )
      {
        grid.push_back(row);
        row.clear();
      }
      value = 0;
    }
  }

  return 0;
}

#include "p18.hpp"
#include "FileLib.hpp"
#include <string>
#include <vector>
MAKE_PROTOTYPE(p18)

//Find the maximum total from top to bottom of the triangle in p18.txt

uint p18::execute() 
{
  std::string s = getFileContents("../p18.txt");

  std::vector<std::string> rows = split(s, '\n');
  std::vector<std::vector<uint> > trinums;

  for ( uint i = 0; i < rows.size(); ++i )
  {
    std::vector<std::string> row = split(rows[i], ' ');
    std::vector<uint> rowAsNums;
    rowAsNums.resize(row.size());
    for ( uint k = 0; k < row.size(); ++k )
    {
      rowAsNums[k] = (unsigned int)atoi(row[k].c_str());
    }
    trinums.push_back(rowAsNums);
  }


  for ( int i = trinums.size() - 2; i >= 0; --i )
  {
    std::vector<uint> &currow = trinums[i];
    std::vector<uint> &prevrow = trinums[i+1];
    for ( uint k = 0; k < currow.size(); k++ )
    {
      currow[k] += prevrow[k+1] > prevrow[k] ? prevrow[k+1] : prevrow[k];
    }
  }
  
  return trinums[0][0];;
}

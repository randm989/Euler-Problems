#include "p15.hpp"
#include "BigInt.hpp"
#include <vector>

MAKE_PROTOTYPE(p15)

//Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//
//
//How many such routes are there through a 20x20 grid?

static std::vector<std::vector<BigInt> > pascals;

static void constructPascals(uint numLayers)
{
  //clear pascals for a new triangle
  pascals.clear();

  //initialize the first row
  std::vector<BigInt> row;
  row.push_back(BigInt(1));
  pascals.push_back(row);

  //populate each row based on the last one
  for( uint i = 1; i < numLayers; ++i )
  {
    row.clear();
    row.push_back(BigInt(1));
    for ( uint k = 1; k < pascals[i-1].size(); ++k )
    {
      row.push_back(BigInt(pascals[i-1][k-1] + pascals[i-1][k]));
    }
    row.push_back(BigInt(1));
    pascals.push_back(row);
  }
}

BigInt p15::execute() 
{
  //We want the number of solutions of a 20 x 20 grid
  uint answerDesired = 20;
  //The answer lies on row 41 of pascal's triangle
  uint rowOfAnswer = answerDesired * 2;

  //Construct the pascals triangle up to 41 rows 
  constructPascals(rowOfAnswer+1);

  //Return the middle element of row 41, that's the number of solutions for a 20 x 20 grid
  return pascals[rowOfAnswer][pascals[rowOfAnswer].size()/2];
}

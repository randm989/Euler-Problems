#include "p11.hpp"
#include "MyMathLib.hpp"
#include "FileLib.hpp"
#include <vector>

//What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 2020 grid?

uint traverse(std::vector<std::vector<uint> > grid, Vector2 start, Vector2 step, uint numsteps)
{
  Vector2 current = start;
  uint curstep = 0;
  Vector2 maxDim;
  maxDim.x = grid[0].size();
  maxDim.y = grid.size();
  uint result = 1;

  while ( curstep < numsteps && current.x >= 0 && current.x < maxDim.x && current.y >= 0 && current.y < maxDim.y )
  {
    result *= grid[current.y][current.x];
    current.y += step.y;
    current.x += step.x;
    ++curstep;
  }
  return result;
}

uint p11::execute() 
{
  std::string s = getFileContents("../p11.txt");

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

  const uint numDirections = 8;
  Vector2 directions[numDirections] = {Vector2(1,1),Vector2(1,0),Vector2(1,-1),Vector2(0,1),Vector2(0,-1),Vector2(-1,1),Vector2(-1,0),Vector2(-1,-1)};
  uint numsteps = 4;
  uint maxResult = 0;

  for ( uint y = 0; y < grid.size(); ++y )
  {
    for ( uint x = 0; x < grid[y].size(); ++x )
    {
      for ( uint i = 0; i < numDirections; ++i )
      {
        uint result = traverse(grid,Vector2(x,y),directions[i],numsteps);
        if ( result > maxResult )
          maxResult = result;
      }
    }
  }
  return maxResult;
}

/*
 * File:   p8.cpp
 * Author: Josh
 *
 * Created on May 23, 2012, 11:29 PM
 * Find the greatest product of five consecutive digits in the 1000-digit number
 */

#include "p8.hpp"
#include <queue>

p8::p8()
{
}

p8::p8(const p8& orig)
{
}

p8::~p8()
{
}

uint p8::execute()
{
  BigInt big;
  big.fromFile("../p8.txt");
  std::queue<uint> queue;

  uint numSize = big.size();
  uint max = 1, digitProduct = 1;
  for( uint i = numSize-1; i > 4; --i )
  {
    uint curnum = big[i];

    if( !curnum )
    {
      while( !queue.empty())
        queue.pop();
      digitProduct = 1;
      continue;
    }

    queue.push(curnum);
    digitProduct *= curnum;

    while( queue.size() > 5 )
    {
      digitProduct /= queue.front();
      queue.pop();
    }
    max = std::max(digitProduct,max);
  }
  return max;
}

#include "p12.hpp"
#include <math.h>

MAKE_PROTOTYPE(p12)

//Let us list the factors of the first seven triangle numbers:
//
// 1: 1
// 3: 1,3
// 6: 1,2,3,6
// 10: 1,2,5,10
// 15: 1,3,5,15
// 21: 1,3,7,21
// 28: 1,2,4,7,14,28
//
//We can see that 28 is the first triangle number to have over five divisors.
//
//What is the value of the first triangle number to have over five hundred divisors?

uint getNumDivisors(uint num)
{
  uint divisor = 1, numDivisors = 0;
  uint limit = (uint)sqrt(num); 

  while (divisor <= limit)
  {
    if ( num % divisor == 0 )
    {
      numDivisors += 2;
      if ( divisor == limit )
        numDivisors--;
    }
    ++divisor;
  }
  return numDivisors;
}



uint p12::execute() 
{
  uint trinum = 0, i = 1, numDivisors = 1;

  while (numDivisors < 500)
  {
    trinum += i++;
    numDivisors = getNumDivisors(trinum);
  }

  return trinum;
}

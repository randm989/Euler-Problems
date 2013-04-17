#include "p16.hpp"
#include "BigInt.hpp"

MAKE_PROTOTYPE(p16)

uint p16::execute() 
{
  BigInt naive = 2;

  naive.exp(1000);
  
  uint sum = 0;
  for ( uint i = 0; i < naive.size(); ++i )
  {
    sum += naive[i]; 
  }
  return sum;
}

#include "p20.hpp"
#include "BigInt.hpp"

MAKE_PROTOTYPE(p20)

uint p20::execute() 
{
  BigInt big(1);
  for ( int i = 1; i < 100; ++i )
  {
    big *= i;
  }
  uint result = 0;
  for ( uint i = 0; i < big.size(); ++i )
  {
    result += big[i]; 
  }
  return result;
}

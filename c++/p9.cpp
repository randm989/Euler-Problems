#include "p9.hpp"

//A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
//
//a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

uint p9::execute() 
{
  int m = 2, n = 1, k = 1;
  while ( m < 50 )
  {
    n = 1;
    while ( n < m )
    {
      int a = m * m - n * n;
      int b = 2 * m * n;
      int c = m * m + n * n;
      k = 1;

      while ( k * ( a + b + c ) < 1000 )
      {
        ++k;
      }
      if ( k * ( a+b+c ) == 1000 )
      {
        // k to the 3rd power because all of a and b and c need to be multiplied by it individually
        return (k*k*k)*a*b*c;
      }
      ++n;
    }
    ++m;
  }
  return 0;
}

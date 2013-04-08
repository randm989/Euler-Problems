#include "p10.hpp"
#include "MyMathLib.hpp"

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

BigInt p10::execute() 
{
  std::vector<unsigned int> primes = MathLib::getInstance().getAllPrimes(2000000);

  BigInt sum = 0;
  for( unsigned int i = 0; i < primes.size(); ++i )
  {
    sum += primes[i];
  }

  return sum;
}

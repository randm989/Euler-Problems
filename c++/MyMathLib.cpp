#include "MyMathLib.hpp"


std::vector<unsigned int> MathLib::getAllPrimes( int upperLimit ) const
{
  std::vector<unsigned int> result;
  for ( int i = 0; i < upperLimit; ++i )
  {
    if ( isPrime(i) )
    {
      result.push_back(i);
    }
  }
  return result;
}

bool MathLib::isPrime( unsigned int numToCheck ) const
{
  if ( numToCheck < _primeSieve.size() )
    return _primeSieve[numToCheck] == 1;

  return false;
}


void MathLib::initPrimeSieve()
{
  _primeSieve.resize(_sieveSize, 1);
  _primeSieve[0] = _primeSieve[1] = 0;

  for ( unsigned int i = 0; i < _primeSieve.size(); ++i )
  {
    if ( _primeSieve[i] == 1 )
    {
      for ( unsigned int k = 2; i*k < _primeSieve.size(); ++k )
      {
        _primeSieve[i*k] = 0;
      }
    }
  }
}

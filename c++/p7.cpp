/*
 * File:   p7.cpp
 * Author: Josh
 *
 * Created on May 23, 2012, 10:10 PM
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

    What is the 10 001st prime number?
 */

#include "p7.hpp"
#include <limits.h>

p7::p7()
{
}

p7::p7(const p7& orig)
{
}

p7::~p7()
{
}

template <class T>
static bool isPrime(T num)
{
  for( T counter = 2; counter*counter <= num ; counter+=1 )
    if( num%counter == 0 )
      return false;
  return true;
}

BigInt p7::execute()
{
  uint numPrimes = 1;
  unsigned int curNum = 3;
  while( numPrimes < 10001 && curNum < INT_MAX )
  {
    if( isPrime(curNum ) )
      numPrimes++;
    curNum+=2;
  }
  return curNum - 2;
}

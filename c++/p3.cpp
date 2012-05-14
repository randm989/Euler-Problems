/*
 * File:   p3.cpp
 * Author: Josh
 *
 * Created on May 13, 2012, 4:36 PM
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include "p3.hpp"
#include "BigInt.hpp"
#include <iostream>

p3::p3()
{
}

p3::p3(const p3& orig)
{
}

p3::~p3()
{
}

BigInt p3::execute()
{
  BigInt modResult,largestFactor=1,big = "600851475143";
  while( big > 1 )
  {
    for( BigInt i = 2; i <= big; i+=1 )
    {
      modResult = big % i;
      if( modResult == 0 )
      {
        largestFactor = largestFactor > i ? largestFactor : i;
        big /= i;
        break;
      }
    }

  }
  return largestFactor;
}
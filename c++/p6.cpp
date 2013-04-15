/*
 * File:   p6.cpp
 * Author: Josh
 *
 * Created on May 23, 2012, 10:00 PM
 *
 * The sum of the squares of the first ten natural numbers is,

    12 + 22 + ... + 102 = 385
    The square of the sum of the first ten natural numbers is,

    (1 + 2 + ... + 10)2 = 552 = 3025
    Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include "p6.hpp"

MAKE_PROTOTYPE(p6)

p6::p6()
{
}

p6::p6(const p6& orig)
{
}

p6::~p6()
{
}

BigInt p6::execute()
{
  BigInt SumOfSquares = 0, sum = 0;
  for( int i = 1; i <= 100; ++i )
  {
    sum += i;
    SumOfSquares += i*i;
  }
  return sum*sum - SumOfSquares;
}

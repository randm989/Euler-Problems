/*
 * File:   p5.cpp
 * Author: Josh
 *
 * Created on May 23, 2012, 2:33 PM
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

   What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 */

#include "p5.hpp"

MAKE_PROTOTYPE(p5)

p5::p5()
{
}

p5::p5(const p5& orig)
{
}

p5::~p5()
{
}

template <class T>
static T gcd(const T &a, const T& b)
{
  if( a == b || a == 0 || b == 0 )
  {
    if( a == 0 )
     return b;
    return a;
  }

  if( a > b )
    return gcd(a%b,b);

  return gcd(a,b%a);
}
template <class T>
static T lcm(const T&a, const T& b)
{
  return (a*b)/gcd(a,b);
}

BigInt p5::execute()
{
  typedef BigInt type;
  type result = 1;
  for( type i = 2; i <= 20; i+=1 )
  {
    result = lcm(result,i);
  }
  return result;
}

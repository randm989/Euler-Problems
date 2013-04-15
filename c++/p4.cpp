/*
 * File:   p4.cpp
 * Author: Josh
 *
 * Created on May 13, 2012, 5:10 PM
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

   Find the largest palindrome made from the product of two 3-digit numbers
 */

#include "p4.hpp"
#include <string>

MAKE_PROTOTYPE(p4)

p4::p4()
{
}

p4::p4(const p4& orig)
{
}

p4::~p4()
{
}

static bool isPalindrome(uint num)
{
  std::string s = "";
  do s.push_back(num%10);
  while( (num/=10) > 0 );

  int ssize = s.size();
  for( int i = 0; i <= ssize/2; ++i)
  {
    if( s[i] != s[(ssize-i)-1])
      return false;
  }
  return true;
}

uint p4::execute()
{
  int largest = 0;
  const int lowBound1 = 900;
  const int lowBound2 = lowBound1 * lowBound1 / 999;
  for( int i = lowBound2; i <= 999; i++ )
  {
    for( int k = lowBound1; k <= 999; k++ )
    {
      largest = (isPalindrome(i*k) && largest < i*k) ? i*k : largest;
    }
  }
  return largest;
}

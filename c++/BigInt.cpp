/*
 * File:   BigInt.cpp
 * Author: Josh
 *
 * Created on May 7, 2012, 1:55 AM
 */

#include "BigInt.hpp"
#include <algorithm>
#include <istream>
#include <fstream>
/*
#include <boost/regex>
#include <boost/foreach>
*/

BigInt::BigInt()
{
  *this = 0;
}

BigInt::BigInt(int i)
{
  *this = i;
}

BigInt::BigInt(const char *s)
{
  *this = s;
}

BigInt::BigInt(const BigInt& orig)
{
  digits = std::deque<BigIntElement> (orig.digits);
}

BigInt::~BigInt()
{
}

uint BigInt::size() const
{
  return this->digits.size();
}

void removeNonNumeric(std::string &s)
{
  std::string result;
  for ( unsigned int i = 0; i < s.length(); ++i )
  {
    if ( s[i] >= '0' && s[i] <= '9' )
      result.push_back(s[i]);
  }
  s = result;
}

BigInt & BigInt::fromFile(const char* filename)
{
  std::ifstream myfile;
  myfile.open(filename);
  std::string s;
  s.assign(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>());
  myfile.close();

  /**
  boost::regex br;
  const char * expression = "[^\\d]";
  br.assign(expression);
  s = boost::regex_replace(s,br,std::string(""),boost::match_default | boost::format_all);
  */

  removeNonNumeric(s);

  return *this = BigInt(s.c_str());
}

std::string BigInt::subset(unsigned int startIndex, unsigned int endIndex)
{
  std::string result;

  for ( unsigned int i = endIndex-1; i >= startIndex; --i )
    result.push_back('0' + digits[i]);

  return result;
}

BigIntElement & BigInt::operator [](unsigned int i)
{
  return digits[i];
}

void BigInt::setDigit(unsigned int index,const BigIntElement &value)
{
  if( digits.size() < index+1 )
  {
    digits.resize(index*2+10,0);
  }
  digits[index] = value;
}

BigInt BigInt::operator +(const BigInt& rhs) const
{
  BigInt result(*this);
  return result += rhs;
}

BigInt & BigInt::operator +=(const BigInt& rhs)
{
  const BigInt* a = this;
  const BigInt* b = &rhs;
  if (*a < *b)
    std::swap(a, b);

  unsigned int i = 0;
  BigIntElement carry = 0;
  const unsigned int bsize = b->digits.size();
  const unsigned int asize = a->digits.size();
  //digits.reserve(asize + 1);

  while (i < asize)
  {
    BigIntElement digit = a->digits[i] + (bsize > i ? b->digits[i] : 0) + carry;
    carry = digit / radix;
    digit %= radix;
    this->setDigit(i++, digit);
  }
  if( carry > 0 )
    this->setDigit(i, carry);

  cleanTrailingZeros();
  return *this;
}

BigInt BigInt::operator /(const BigInt& rhs) const
{
  BigInt result = *this;
  return result /= rhs;
}

BigInt & BigInt::operator /=(const BigInt& rhs)
{
  const BigInt *dividend = this; //The Bigger one
  const BigInt *divisor = &rhs; // The smaller one
  BigInt quotient; // the result
  BigInt remainder = 0;

  int i = dividend->digits.size() - 1;
  quotient.digits.resize(i+1,0);
  while( i >= 0 )
  {
    remainder *= radix;
    remainder += dividend->digits[i];
    while( remainder >= *divisor )
    {
      remainder -= *divisor;
      quotient.setDigit(i, quotient[i] + 1);
    }
    --i;
  }
  *this = quotient;
  cleanTrailingZeros();
  return *this;
}
BigInt BigInt::operator *(const BigInt& rhs) const
{
  BigInt result = *this;
  return result *= rhs;
}

BigInt &BigInt::operator*=(const BigInt& rhs)
{
  unsigned int i = 0, k = 0;
  BigInt temp,result;

  const BigInt *a = this;
  const BigInt *b = &rhs;

  if( *b > *a )
    std::swap(a,b);

  BigIntElement carry = 0;
  const std::deque<BigIntElement> &ad = a->digits, &bd = b->digits;
  unsigned int bLength = bd.size(), aLength = ad.size();
  //temp.digits.reserve(bLength + aLength + 1);

  while( i < bLength )
  {
    k = 0;
    carry = 0;
    temp = 0;
    while( k < aLength )
    {
      BigIntElement digitResult = ad[k] * bd[i] + carry;
      carry = digitResult / result.radix;
      digitResult %= result.radix;
      temp.setDigit(i+k++, digitResult);
    }
    if( carry > 0 )
      temp.setDigit(i+k, carry);

    result += temp;
    ++i;
  }
  *this = result;
  cleanTrailingZeros();
  return *this;
}

BigInt BigInt::operator -(const BigInt& rhs) const
{
  BigInt result(*this);
  return result -= rhs;
}

BigInt & BigInt::operator -=(const BigInt& rhs)
{
  const BigInt* a = this;
  const BigInt* b = &rhs;
  if (*a < *b)
    std::swap(a, b);

  unsigned int i = 0;
  BigIntElement borrow = 0;
  const unsigned int minuendSize = b->digits.size();
  while (i < a->digits.size())
  {
    BigIntElement newDigit = a->digits[i] - (minuendSize > i ? b->digits[i] : 0) - borrow;
    borrow = 0;
    if (newDigit < 0)
    {
      borrow = 1;
      newDigit += radix;
    }

    if (digits.size() <= i)
      digits.push_back(newDigit);
    else
      digits[i] = newDigit;
    ++i;
  }
  cleanTrailingZeros();
  return *this;
}

BigInt BigInt::operator%(const BigInt &rhs) const
{
  BigInt result = *this;
  return result %= rhs;
}

BigInt &BigInt::operator%=(const BigInt &rhs)
{
  const BigInt *dividend = this; //The Bigger one
  const BigInt *divisor = &rhs; // The smaller one
  BigInt remainder = 0;

  int i = dividend->digits.size() - 1;
  while( i >= 0 )
  {
    remainder *= radix;
    remainder += dividend->digits[i];
    while( remainder >= *divisor )
      remainder -= *divisor;
    --i;
  }
  *this = remainder;
  cleanTrailingZeros();
  return *this;
}
BigInt & BigInt::operator =(int rhs)
{
  this->digits.clear();
  do
  {
    BigIntElement c = static_cast<BigIntElement> (rhs % 10);
    this->digits.push_back(c);
  }
  while (rhs /= 10);
  return *this;
}

BigInt & BigInt::operator =(const char *rhs)
{
  this->digits.clear();

  while (*rhs) 
  {
    this->digits.push_front(*rhs - '0');
    ++rhs;
  }
  return *this;
}


BigInt::operator  std::string() const
{
  return this->toString();
}

std::string BigInt::toString() const
{
  BigIntElement digit;
  std::string result;
  result.reserve(digits.size());
  std::deque<BigIntElement>::const_iterator i;

  for ( i = digits.begin(); i != digits.end(); ++i )
  {
    digit = *i;
    if( digit > 10 )
      result.push_back('A' + (digit-10));
    else
      result.push_back('0' + digit);
  }
  std::reverse(result.begin(), result.end());
  /**
  BOOST_REVERSE_FOREACH(digit, digits)
  {
    if( digit > 10 )
      result.push_back('A' + (digit-10));
    else
      result.push_back('0' + digit);
  }
  */

  return result;
}

int BigInt::compare(const BigInt& lhs, const BigInt& rhs) const
{
  if (this->digits.size() == rhs.digits.size())
  {
    int i = digits.size();
    while (--i >= 0)
    {
      if (digits[i] > rhs.digits[i])
        return 1;
      else if (digits[i] < rhs.digits[i])
        return -1;
    }
    return 0;
  }
  else
  {
    return (this->digits.size() > rhs.digits.size()) ? 1 : -1;
  }
}

bool BigInt::operator>=(const BigInt& rhs) const
{
  return compare(*this,rhs) >= 0;
}

bool BigInt::operator>(const BigInt& rhs) const
{
  return compare(*this,rhs) > 0;
}

bool BigInt::operator<=(const BigInt& rhs) const
{
  return compare(*this,rhs) <= 0;
}
bool BigInt::operator<(const BigInt& rhs) const
{
  return compare(*this,rhs) < 0;
}

bool BigInt::operator==(const BigInt& rhs) const
{
  return compare(*this,rhs) == 0;
}

void BigInt::cleanTrailingZeros()
{
  unsigned int newSize = digits.size();
  while( newSize > 1 && digits[newSize-1] == 0)
    --newSize;
  digits.resize(newSize,0);
}

std::ostream& operator << (std::ostream& osObject, const BigInt& bi)
{
  osObject << bi.toString();
  return osObject;
}

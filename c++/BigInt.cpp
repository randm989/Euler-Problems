/*
 * File:   BigInt.cpp
 * Author: Josh
 *
 * Created on May 7, 2012, 1:55 AM
 */

#include "BigInt.hpp"
#include <algorithm>
#include <boost/foreach.hpp>

BigInt::BigInt()
{
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
    digits = std::vector<BigIntElement>(orig.digits);
}

BigInt::~BigInt()
{
}

BigIntElement & BigInt::operator [](unsigned int i)
{
    return digits[i];
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
    if( *a < *b )
        std::swap(a,b);

    BigIntElement i = 0;
    BigIntElement carry = 0;
    const int aduendSize = b->digits.size();
    while( i < a->digits.size() )
    {
        BigIntElement digit = a->digits[i] + (aduendSize > i ? b->digits[i] : 0) + carry;
        carry = digit/radix;
        digit %= radix;

        if( digits.size() <= i )
            digits.push_back(digit);
        else
            digits[i++] = digit;
    }
    return *this;
}

BigInt BigInt::operator -(const BigInt& rhs) const
{
    return BigInt();
}

BigInt & BigInt::operator -=(const BigInt& rhs)
{
    return *this;
}

BigInt & BigInt::operator =(int rhs)
{
    this->digits.clear();
    do
    {
        BigIntElement c = static_cast<BigIntElement>(rhs%10);
        this->digits.push_back(c);
    }
    while ( rhs /= 10 );
    return *this;
}

BigInt & BigInt::operator =(const char *rhs)
{
    this->digits.clear();
    char el;
    BOOST_REVERSE_FOREACH(el, rhs)
    {
        this->digits.push_back(el - '0');
    }
    return *this;
}

std::string BigInt::toString()
{
    BigIntElement digit;
    std::string result;
    result.reserve(digits.size());
    BOOST_REVERSE_FOREACH(digit, digits)
    {
        result.push_back('0' + digit);
    }
    return result;
}

bool BigInt::operator>(const BigInt& rhs) const
{
    if( this->digits.size() == rhs.digits.size() )
    {
        int i = digits.size();
        while( --i >= 0 )
        {
            if( digits[i] > rhs.digits[i] )
                return true;
            else if( digits[i] < rhs.digits[i] )
                return false;
        }
        return false;
    } else
    {
        return this->digits.size() > rhs.digits.size();
    }
}

bool BigInt::operator <(const BigInt& rhs) const
{
    return (rhs > *this);
}

bool BigInt::operator==(const BigInt& rhs) const
{
    if( digits.size() != rhs.digits.size() )
        return false;

    for( int i = digits.size()-1; i >= 0; --i )
    {
        if (digits[i] != rhs.digits[i] )
            return false;
    }
    return true;
}
/*
 * File:   BigInt.hpp
 * Author: Josh
 *
 * Created on May 7, 2012, 1:55 AM
 */

#ifndef BIGINT_HPP
#define	BIGINT_HPP
#include <vector>
#include <string>

typedef char BigIntElement;

class BigInt
{
public:
    BigInt();
    BigInt(int);
    BigInt(const char *);
    BigInt(const BigInt& orig);
    virtual ~BigInt();

    std::string toString();

    BigInt & operator=(int);
    BigInt & operator=(const char *);
    BigIntElement &operator[](unsigned int);

    bool operator>(const BigInt &) const;
    bool operator<(const BigInt &) const;
    bool operator==(const BigInt &) const;

    BigInt operator+(const BigInt &) const;
    BigInt & operator+=(const BigInt &);

    BigInt operator-(const BigInt &) const;
    BigInt & operator-=(const BigInt &);


private:
    std::vector<BigIntElement> digits;
    static const unsigned char radix = 10;
};

#endif	/* BIGINT_HPP */


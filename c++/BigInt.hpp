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
#include <ostream>

typedef char BigIntElement;

class BigInt
{
public:
  BigInt();
  BigInt(int);
  BigInt(const char *);
  BigInt(const BigInt& orig);
  virtual ~BigInt();

  operator std::string() const;
  std::string toString() const;

  BigInt & operator=(int);
  BigInt & operator=(const char *);
  BigIntElement &operator[](unsigned int);

  BigInt operator*(const BigInt &) const;
  BigInt & operator*=(const BigInt &);

  BigInt operator/(const BigInt &) const;
  BigInt &operator/=(const BigInt &);
  BigInt operator%(const BigInt &) const;
  BigInt &operator%=(const BigInt &);

  bool operator>(const BigInt &) const;
  bool operator>=(const BigInt &) const;
  bool operator<(const BigInt &) const;
  bool operator<=(const BigInt &) const;
  bool operator==(const BigInt &) const;

  BigInt operator+(const BigInt &) const;
  BigInt & operator+=(const BigInt &);

  BigInt operator-(const BigInt &) const;
  BigInt & operator-=(const BigInt &);


private:
  std::vector<BigIntElement> digits;
  static const unsigned char radix = 10;

  void setDigit(unsigned int index, const BigIntElement &value);
  void cleanTrailingZeros();
  int compare(const BigInt &lhs, const BigInt &rhs) const;
};


#endif	/* BIGINT_HPP */


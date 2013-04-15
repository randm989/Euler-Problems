/*
 * File:   BigInt.hpp
 * Author: Josh
 *
 * Created on May 7, 2012, 1:55 AM
 */

#ifndef BIGINT_HPP
#define	BIGINT_HPP
#include <deque>
#include <string>
#include <ostream>

typedef char BigIntElement;
typedef unsigned int uint;

class BigInt
{
public:
  BigInt();
  BigInt(int);
  BigInt(const char *);
  BigInt(const BigInt& orig);
  virtual ~BigInt();

  BigInt &fromFile(const char* filename);

  operator std::string() const;
  std::string toString() const;

  BigInt & operator=(int);
  BigInt & operator=(const char *);
  BigIntElement &operator[](unsigned int);
  std::string subset(unsigned int startIndex, unsigned int endIndex);

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

  uint size() const;

private:
  std::deque<BigIntElement> digits;
  static const unsigned char radix = 10;

  void setDigit(unsigned int index, const BigIntElement &value);
  void cleanTrailingZeros();
  int compare(const BigInt &lhs, const BigInt &rhs) const;
};

std::ostream& operator << (std::ostream& osObject, const BigInt& bi);

#endif	/* BIGINT_HPP */


/*
 * File:   p6.hpp
 * Author: Josh
 *
 * Created on May 23, 2012, 10:00 PM
 */

#ifndef P6_HPP
#define	P6_HPP

#include "EulerProblem.hpp"
#include "BigInt.hpp"


class p6 : public EulerProblem<BigInt>
{
public:
  p6();
  p6(const p6& orig);
  virtual ~p6();

  BigInt execute();
private:

};

#endif	/* P6_HPP */


/*
 * File:   p7.hpp
 * Author: Josh
 *
 * Created on May 23, 2012, 10:10 PM
 */

#ifndef P7_HPP
#define	P7_HPP

#include "EulerProblem.hpp"
#include "BigInt.hpp"


class p7 : public EulerProblem<BigInt>
{
public:
  p7();
  p7(const p7& orig);
  virtual ~p7();

  BigInt execute();
private:

};

#endif	/* P7_HPP */


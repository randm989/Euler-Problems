/*
 * File:   p15.hpp
 * Author: Josh
 *
 * Created on April 10, 2015
 */

#ifndef P15_HPP
#define	P15_HPP

#include "EulerProblem.hpp"

class BigInt;

class p15 : public EulerProblem<BigInt>
{
public:
  p15(){}
  p15(const p15& orig){}
  virtual ~p15(){}

  BigInt execute();
private:

};

#endif	/* P15_HPP */


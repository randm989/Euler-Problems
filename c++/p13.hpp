/*
 * File:   p13.hpp
 * Author: Josh
 *
 * Created on April 10, 2013
 */

#ifndef P13_HPP
#define	P13_HPP

#include "EulerProblem.hpp"
#include "BigInt.hpp"

class p13 : public EulerProblem<BigInt>
{
public:
  p13(){}
  p13(const p13& orig){}
  virtual ~p13(){}

  BigInt execute();
private:

};

#endif	/* P13_HPP */


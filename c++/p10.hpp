/*
 * File:   p10.hpp
 * Author: Josh
 *
 * Created on April 2, 2013
 */

#ifndef P10_HPP
#define	P10_HPP

#include "EulerProblem.hpp"
#include "BigInt.hpp"

class p10 : public EulerProblem<BigInt>
{
public:
  p10(){}
  p10(const p10& orig){}
  virtual ~p10(){}

  BigInt execute();
private:

};

#endif	/* P10_HPP */


/*
 * File:   p12.hpp
 * Author: Josh
 *
 * Created on April 9, 2013
 */

#ifndef P12_HPP
#define	P12_HPP

#include "EulerProblem.hpp"

class p12 : public EulerProblem<uint>
{
public:
  p12(){}
  p12(const p12& orig){}
  virtual ~p12(){}

  uint execute();
private:

};

#endif	/* P12_HPP */


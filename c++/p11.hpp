/*
 * File:   p11.hpp
 * Author: Josh
 *
 * Created on April 9, 2013
 */

#ifndef P11_HPP
#define	P11_HPP

#include "EulerProblem.hpp"

class p11 : public EulerProblem<uint>
{
public:
  p11(){}
  p11(const p11& orig){}
  virtual ~p11(){}

  uint execute();
private:

};

#endif	/* P11_HPP */


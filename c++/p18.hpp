/*
 * File:   p18.hpp
 * Author: Josh
 *
 * Created on April 10, 2018
 */

#ifndef P18_HPP
#define	P18_HPP

#include "EulerProblem.hpp"

class p18 : public EulerProblem<uint>
{
public:
  p18(){}
  p18(const p18& orig){}
  virtual ~p18(){}

  uint execute();
private:

};

#endif	/* P18_HPP */


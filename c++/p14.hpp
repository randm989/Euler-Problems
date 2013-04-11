/*
 * File:   p14.hpp
 * Author: Josh
 *
 * Created on April 10, 2014
 */

#ifndef P14_HPP
#define	P14_HPP

#include "EulerProblem.hpp"

class p14 : public EulerProblem<uint>
{
public:
  p14(){}
  p14(const p14& orig){}
  virtual ~p14(){}

  uint execute();
private:

};

#endif	/* P14_HPP */


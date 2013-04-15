/*
 * File:   p16.hpp
 * Author: Josh
 *
 * Created on April 10, 2016
 */

#ifndef P16_HPP
#define	P16_HPP

#include "EulerProblem.hpp"

class p16 : public EulerProblem<uint>
{
public:
  p16(){}
  p16(const p16& orig){}
  virtual ~p16(){}

  uint execute();
private:

};

#endif	/* P16_HPP */


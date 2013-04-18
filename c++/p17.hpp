/*
 * File:   p17.hpp
 * Author: Josh
 *
 * Created on April 10, 2017
 */

#ifndef P17_HPP
#define	P17_HPP

#include "EulerProblem.hpp"

class p17 : public EulerProblem<uint>
{
public:
  p17(){}
  p17(const p17& orig){}
  virtual ~p17(){}

  uint execute();
private:

};

#endif	/* P17_HPP */


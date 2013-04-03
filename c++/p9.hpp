/*
 * File:   p9.hpp
 * Author: Josh
 *
 * Created on April 2, 2013, 11:29 PM
 */

#ifndef P9_HPP
#define	P9_HPP

#include "EulerProblem.hpp"

class p9 : public EulerProblem<uint>
{
public:
  p9(){}
  p9(const p9& orig){}
  virtual ~p9(){}

  uint execute();
private:

};

#endif	/* P9_HPP */


/*
 * File:   p4.hpp
 * Author: Josh
 *
 * Created on May 13, 2012, 5:10 PM
 */

#ifndef P4_HPP
#define	P4_HPP
#include "EulerProblem.hpp"

typedef unsigned int uint;

class p4 : public EulerProblem<uint>
{
public:
  p4();
  p4(const p4& orig);
  virtual ~p4();

  uint execute();
private:

};

#endif	/* P4_HPP */


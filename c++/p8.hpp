/*
 * File:   p8.hpp
 * Author: Josh
 *
 * Created on May 23, 2012, 11:29 PM
 */

#ifndef P8_HPP
#define	P8_HPP

#include "EulerProblem.hpp"
#include "BigInt.hpp"


class p8 : public EulerProblem<uint>
{
public:
  p8();
  p8(const p8& orig);
  virtual ~p8();

  uint execute();
private:

};

#endif	/* P8_HPP */


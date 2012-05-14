/*
 * File:   p3.hpp
 * Author: Josh
 *
 * Created on May 13, 2012, 4:36 PM
 */

#ifndef P3_HPP
#define	P3_HPP
#include "EulerProblem.hpp"
#include "BigInt.hpp"

class p3 : public EulerProblem<BigInt>
{
public:
  p3();
  p3(const p3& orig);
  virtual ~p3();

  BigInt execute();
private:

};

#endif	/* P3_HPP */


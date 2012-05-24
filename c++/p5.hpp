/*
 * File:   p5.hpp
 * Author: Josh
 *
 * Created on May 23, 2012, 2:33 PM
 */

#ifndef P5_HPP
#define	P5_HPP
/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

   What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 */

#include "EulerProblem.hpp"
#include "BigInt.hpp"


class p5 : public EulerProblem<BigInt>
{
public:
  p5();
  p5(const p5& orig);
  virtual ~p5();

  BigInt execute();
private:

};

#endif	/* P5_HPP */


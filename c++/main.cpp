/*
 * File:   main.cpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:29 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "p1.hpp"
#include "p2.hpp"
#include "p3.hpp"
#include "p4.hpp"
#include "BigInt.hpp"
#include "p5.hpp"
#include "p6.hpp"
#include "p7.hpp"
#include "p8.hpp"
#include "p9.hpp"
#include "p10.hpp"
#include "p11.hpp"
#include "p12.hpp"
#include "p13.hpp"
#include "p14.hpp"
#include "p15.hpp"

using namespace std;

void compareTest() {
  BigInt big = 2;
  BigInt small = 1;
  cout << "2=2" << endl;
  assert(big == big);
  assert((big == small) == false);
  cout << "2>1" << endl;
  assert(big > small);
  assert((big > big) == false);
  assert((small > big) == false);
  cout << "1<2" << endl;
  assert(small < big);
  assert((small < small) == false);
  assert((big < small) == false);
  cout << "1<=2&&2<=2" << endl;
  assert(small <= big && big <= big);
  cout << "2>=1&&2>=2" << endl;
  assert(big >= small && big >= 2);
}

void SumTest()
{
  int adduend = 19;
  for( int i = 5; i < 265; i+= 10 )
  {
    BigInt bi = i;
    bool result = (bi+adduend) == i + adduend;
    cout << i << " + " << adduend << " = " << i + adduend;
    cout << " (" << (string)(bi+adduend) << ") " << (result ? "true" : "false") << endl;
    assert(result);
  }
}

void MinusTest()
{
  int minuend = 239;
  for( int i = minuend + 12; i < 500; i+=8)
  {
    BigInt bi = i;
    bool result = (bi-minuend) == (i - minuend);
    cout << i << " - " << minuend << " = " << i - minuend;
    cout << " (" << (string)(bi-minuend) << ") " << (result ? "true" : "false") << endl;
    assert(result);
  }
}

void MultTest()
{
  int rhs = 2239;
  for( int i = rhs + 12; i < 53200; i+=8224)
  {
    BigInt bi = i;
    bool result = (bi*rhs) == i * rhs;
    cout << i << " * " << rhs << " = " << i * rhs;
    cout << " (" << (string)(bi*rhs) << ") " << (result ? "true" : "false") << endl;
    assert(result);
  }
}

void DivTest()
{
  int rhs = 133;
  for( int i = rhs + 124434; i < 5242400; i+=3678)
  {
    BigInt bi = i;
    bool result = (bi/rhs) == i / rhs;
    cout << i << " / " << rhs << " = " << i / rhs;
    cout << " (" << (string)(bi/rhs) << ") " << (result ? "true" : "false") << endl;
    assert(result);
  }
}

void ModTest()
{
  int rhs = 1355555;
  for( int i = rhs + 12; i < 52200; i+=668)
  {
    BigInt bi = i;
    bool result = (bi%rhs) == i % rhs;
    cout << i << " % " << rhs << " = " << i % rhs;
    cout << " (" << (string)(bi%rhs) << ") " << (result ? "true" : "false") << endl;
    assert(result);
  }
}

/*
 *
 */
int main(int argc, char** argv)
{
  if ( argc > 1 && strcmp(argv[1], "debug") == 0 )
  {
    compareTest();
    SumTest();
    MinusTest();
    MultTest();
    DivTest();
    ModTest();
  }

  EulerProblemBase *problems[] = {new p1(),
                                  new p2(),
                                  new p3(),
                                  new p4(),
                                  new p5(),
                                  new p6(),
                                  new p7(),
                                  new p8(),
                                  new p9(),
                                  new p10(),
                                  new p11(),
                                  new p12(),
                                  new p13(),
                                  new p14(),
                                  new p15()};
  uint psize = sizeof(problems) / sizeof(problems[0]);

  for ( uint i = 0; i != psize; ++i )
  {
    cout << "P" << i+1 << ": " << *problems[i] << endl;
    delete problems[i];
  }

  return 0;
}


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
  compareTest();
  SumTest();
  MinusTest();
  MultTest();
  DivTest();
  ModTest();
  cout << "P1: " << Problem1().execute() << endl;
  cout << "P2: " << Problem2().execute() << endl;
  cout << "P3: " << (string)p3().execute() << endl;
  cout << "P4: " << p4().execute() << endl;
  cout << "P5: " << (string)p5().execute() << endl;

  return 0;
}


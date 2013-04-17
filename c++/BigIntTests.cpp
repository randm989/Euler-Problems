#include "BigInt.hpp"
#include <assert.h>
#include <iostream>

using namespace std;

void BigIntTests::execute()
{
  compareTest();
  SumTest();
  MinusTest();
  MultTest();
  DivTest();
  ModTest();
  ExpTest();
}


void BigIntTests::ExpTest()
{
  BigInt num = 6;

  assert(num.exp(0) == 1);
  num = 6;
  assert(num.exp(1) == 6);
  num = 6;
  num.exp(2);
  assert(num == 36);
  num = 6;
  num.exp(3);
  assert(num == 216);

  num = 1;

  assert(num.exp(1000) == 1);

  cout << "exp tests passed" << endl;
}

void BigIntTests::compareTest() 
{
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

void BigIntTests::SumTest()
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

void BigIntTests::MinusTest()
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

void BigIntTests::MultTest()
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

void BigIntTests::DivTest()
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

void BigIntTests::ModTest()
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

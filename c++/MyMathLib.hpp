#ifndef MATHLIB_HPP
#define MATHLIB_HPP

#include <vector>

class MathLib
{
  public:
    static const MathLib & getInstance() { static MathLib instance; return instance; }

    std::vector<unsigned int> getAllPrimes( int upperLimit ) const; 
    bool isPrime( unsigned int numToCheck ) const;

  private:
    std::vector<unsigned int> _primeSieve;
    const unsigned int _sieveSize;

    MathLib():_sieveSize(2000000){initPrimeSieve();}
    MathLib(MathLib const &):_sieveSize(2000000){}
    void operator=(MathLib const &){}

    void initPrimeSieve();
};

struct Vector2
{
  Vector2() { x = y = 0; }
  Vector2(int _x, int _y) { x = _x; y = _y; }
  int x;
  int y;
};

#endif

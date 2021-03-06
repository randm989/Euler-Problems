/*
 * File:   main.cpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "EulerProblem.hpp"
#include "BigInt.hpp"

using namespace std;

std::string convertInt(int number)
{
  std::stringstream ss;//create a stringstream
  ss << number;//add number to the stream
  return ss.str();//return a string with the contents of the stream
}

/*
 *
 */
int main(int argc, char** argv)
{
  uint probMin = 1, probMax = 30;
  if ( argc > 1 )
  {
    probMax = atoi(argv[1]);
    if ( argc > 2 )
    {
      probMin = atoi(argv[1]) > 0 ? atoi(argv[1]) : 1;
      probMax = atoi(argv[2]);
    }
  }

  std::map<std::string, EulerProblemBase*>::iterator iter = EulerProblemBase::protoTable.begin();
  for ( unsigned int i = probMin; i <= probMax; ++i )
  {
    iter = EulerProblemBase::protoTable.find(std::string("p") + convertInt(i));
    if ( iter != EulerProblemBase::protoTable.end() )
    {
      cout << "Executing " << iter->first << ": " << *(iter->second) << endl;
    }
    else
    {
      cout << "Problem " << i << " not found." << endl;
    }
  }

  EulerProblemBase::cleanupPrototypes();

  return 0;
}


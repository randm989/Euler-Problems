#include "p14.hpp"
#include <vector>
#include <stack>

//The following iterative sequence is defined for the set of positive integers:
//
//n ->  n/2 (n is even)
//n ->  3n + 1 (n is odd)
//
//Which starting number, under one million, produces the longest chain?
//
//
static std::vector<uint> answerMap;

uint collatz(uint start)
{
  std::stack<uint> steps;
  uint curStep = start;
  steps.push(curStep);

  while ( curStep != 1 )
  {
    if ( answerMap.size() > curStep && answerMap[curStep] != 0 )
    {
      steps.push(curStep);
      break;
    }
    if ( curStep % 2 == 0 )
      curStep /= 2;
    else
      curStep = 3 * curStep + 1;
    steps.push(curStep);
  }

  uint answerSteps = answerMap[steps.top()];
  steps.pop();

  while ( steps.empty() == false )
  {
    if ( steps.top() < answerMap.size() )
      answerMap[steps.top()] = answerSteps;
    steps.pop();
    ++answerSteps;
  }

  return answerMap[start];
}

uint p14::execute() 
{
  answerMap.resize(1000000,0);
  answerMap[0] = answerMap[1] = 1;
  
  uint answer = 1, maxStepsFound = 1;

  for ( uint i = 1; i < 1000000; ++i )
  {
    uint col = collatz(i);
    if ( maxStepsFound < col )
    {
      answer = i;
      maxStepsFound = col;
    }
  }
  return answer;
}

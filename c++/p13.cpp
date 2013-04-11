#include "p13.hpp"
#include "FileLib.hpp"
#include <string>
#include <vector>

//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers. (../p13.txt)


BigInt p13::execute() 
{
  std::string s = getFileContents("../p13.txt");
  BigInt sum;

  std::vector<std::string> numStrings = split(s, '\n');

  for ( uint i = 0; i < numStrings.size(); ++i )
  {
    sum += BigInt(numStrings[i].c_str());
  }
  
  uint answerSize = sum.size();

  return BigInt(sum.subset(answerSize-10,answerSize).c_str());
}

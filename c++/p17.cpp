#include "p17.hpp"
#include <string>

MAKE_PROTOTYPE(p17)

static const char *ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const char *tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
static const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static const char *hundred = "hundred";

static std::string constructNumberWord(uint num)
{
  std::string result;
  uint numHund = num / 100;
  uint numTen = (num - numHund*100) / 10;
  uint numOnes = num - (numHund*100 + numTen*10);

  if ( numHund > 0 )
  {
    result += ones[numHund - 1];
    result += hundred;
    if ( numHund*100 < num )
      result += "and";
  }

  if ( numTen > 1 )
  {
    result += tens[numTen-1];
  }
  else if ( numTen == 1 )
  {
    result += teens[numOnes];
    return result;
  }
    
  if ( numOnes > 0 )
  {
    result += ones[numOnes - 1];
  }

  return result;
}

uint p17::execute() 
{
  uint result = 0;
  for ( uint i = 1; i < 1000; ++i )
  {
    result += constructNumberWord(i).size();
  }

  result += std::string("onethousand").size();

  return result;
}

#include "p19.hpp"

MAKE_PROTOTYPE(p19)

static int daysInMonth(uint year, uint month)
{
  uint days = 31;
  if ( month == 3 || month == 5 || month == 8 || month == 10 )
  {
    days = 30;
  }

  if ( month == 2 )
  {
    days = 28;
    if ( month % 4 == 0 && !(month % 100 == 0 && month % 400 != 0) )
    {
      days = 29;
    }
  }

  return days;
}

int p19::execute() 
{
  uint curYear = 1900;
  uint curMonth = 0;
  uint curDayOfWeek = 1;
  uint numSundays = 0;

  while ( curYear <= 2000 )
  {
    for ( curMonth = 0; curMonth < 12; ++curMonth )
    {
      if ( curYear > 1900 && curDayOfWeek == 0 )
      { 
        numSundays++;
      }
      curDayOfWeek += daysInMonth(curYear, curMonth);
      curDayOfWeek %= 7;
    }
    curYear++; 
  }
  return numSundays;
}

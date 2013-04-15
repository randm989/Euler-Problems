#include "p1.hpp"

MAKE_PROTOTYPE(p1)

int p1::execute() 
{
    int sum = 0;
    for( int i = 0; i < 1000; i++ ) 
    {
        if( i%3==0 || i%5 == 0 ) 
        {
            sum += i;
        }
    }
    return sum;
}

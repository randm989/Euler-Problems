/* 
 * File:   p2.cpp
 * Author: Josh
 * 
 * Created on May 4, 2012, 6:52 PM
 */

#include "p2.hpp"

Problem2::Problem2() {
}

Problem2::Problem2(const Problem2& orig) {
}

Problem2::~Problem2() {
}

uint Problem2::execute() 
{
    uint result = 0;
    
    uint prevI = 0, i = 1;
    while( i < 4000000 )
    {
        if( !(i&1) ) 
        {
            result+=i;
        }
        uint tmp = prevI;
        prevI = i;
        i+=tmp;
    }
    return result;
}


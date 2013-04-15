/* 
 * File:   p1.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:51 PM
 */

#ifndef P1_HPP
#define	P1_HPP
#include "EulerProblem.hpp"

class p1 : public EulerProblem<int> {
public:
    p1(){}
    virtual ~p1(){}

    int execute();
private:
    
};


#endif	/* P1_HPP */


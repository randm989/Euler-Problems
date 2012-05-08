/* 
 * File:   p1.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:51 PM
 */

#ifndef P1_HPP
#define	P1_HPP
#include "EulerProblem.hpp"

class Problem1 : public EulerProblem<int> {
public:
    Problem1(){}
    virtual ~Problem1(){}
    
    int execute();
private:
    
};


#endif	/* P1_HPP */


/* 
 * File:   p21.hpp
 * Author: Josh
 *
 */

#ifndef P21_HPP
#define	P21_HPP
#include "EulerProblem.hpp"

class p21 : public EulerProblem<int> {
public:
    p21(){}
    virtual ~p21(){}

    int execute();
private:
    
};


#endif	/* P21_HPP */


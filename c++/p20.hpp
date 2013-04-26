/* 
 * File:   p20.hpp
 * Author: Josh
 *
 */

#ifndef P20_HPP
#define	P20_HPP
#include "EulerProblem.hpp"

class p20 : public EulerProblem<uint> {
public:
    p20(){}
    virtual ~p20(){}

    uint execute();
private:
    
};


#endif	/* P20_HPP */


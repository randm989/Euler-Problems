/*
 * File:   p2.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 6:52 PM
 */

#ifndef P2_HPP
#define	P2_HPP
#include "EulerProblem.hpp"

typedef unsigned int uint;

class p2 : public EulerProblem<uint> {
public:
    p2();
    p2(const p2& orig);
    virtual ~p2();

    uint execute();
private:

};

#endif	/* P2_HPP */


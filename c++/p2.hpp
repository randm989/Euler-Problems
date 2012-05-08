/*
 * File:   p2.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 6:52 PM
 */

#ifndef P2_HPP
#define	P2_HPP
#include "EulerProblem.hpp"

class Problem2 : public EulerProblem<uint> {
public:
    Problem2();
    Problem2(const Problem2& orig);
    virtual ~Problem2();

    uint execute();
private:

};

#endif	/* P2_HPP */


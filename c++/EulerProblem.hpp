/*
 * File:   EulerProblem.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:58 PM
 */

#ifndef EULERPROBLEM_HPP
#define	EULERPROBLEM_HPP
#include <cstddef>

template<class T>
class EulerProblem
{
public:
    virtual ~EulerProblem(){}

    virtual T execute() = 0;

protected:

private:

};

typedef unsigned int uint;

#endif	/* EULERPROBLEM_HPP */


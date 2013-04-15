/*
 * File:   EulerProblem.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:58 PM
 */

#ifndef EULERPROBLEM_HPP
#define	EULERPROBLEM_HPP
#include <ostream>

class EulerProblemBase
{
  public:
    virtual void executeToOstream(std::ostream& stream) = 0;
};


std::ostream& operator<<(std::ostream& stream, EulerProblemBase &base);

template<class T>
class EulerProblem : public EulerProblemBase
{
public:
    virtual ~EulerProblem(){}
    virtual T execute() = 0;

    virtual void executeToOstream(std::ostream& stream) { stream << this->execute(); }

protected:

private:

};

template <>
class EulerProblem<unsigned int> : public EulerProblemBase
{
public:
    virtual ~EulerProblem(){}
    virtual unsigned int execute() = 0;

    virtual void executeToOstream(std::ostream& stream) { stream << this->execute(); }

protected:

private:

};

typedef unsigned int uint;

#endif	/* EULERPROBLEM_HPP */


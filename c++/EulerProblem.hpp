/*
 * File:   EulerProblem.hpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:58 PM
 */

#ifndef EULERPROBLEM_HPP
#define	EULERPROBLEM_HPP
#include <ostream>
#include <map>
#include <string>

#define MAKE_PROTOTYPE(TYPE) EulerProblemBase * TYPE##_prototype = EulerProblemBase::addProblemPrototype(#TYPE, new TYPE());

class EulerProblemBase
{
  public:
    virtual void executeToOstream(std::ostream& stream) = 0;

    static std::map<std::string, EulerProblemBase*> protoTable;
    static EulerProblemBase *addProblemPrototype(std::string key, EulerProblemBase *);
    static void cleanupPrototypes();
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


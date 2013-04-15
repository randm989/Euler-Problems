#include "EulerProblem.hpp"

std::map<std::string, EulerProblemBase*> EulerProblemBase::protoTable;

std::ostream& operator<<(std::ostream& stream, EulerProblemBase &base)
{
  base.executeToOstream(stream);
  return stream;
}

EulerProblemBase * EulerProblemBase::addProblemPrototype(std::string key, EulerProblemBase *problem)
{
  protoTable[key] = problem; 
  return protoTable[key];
}

void EulerProblemBase::cleanupPrototypes()
{
  std::map<std::string, EulerProblemBase*>::iterator iter = protoTable.begin();

  while( iter != protoTable.end() )
  {
    delete iter->second;
    ++iter;
  }
  
  protoTable.clear();
}

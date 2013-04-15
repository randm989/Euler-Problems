#include "EulerProblem.hpp"

std::ostream& operator<<(std::ostream& stream, EulerProblemBase &base)
{
  base.executeToOstream(stream);
  return stream;
}

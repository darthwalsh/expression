#include "constant.hpp"

constant::constant(int nn)
: n(nn)
{ }

int constant::evaluate()
{
  return n;
}
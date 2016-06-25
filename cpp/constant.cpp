#include "constant.hpp"

constant::constant(int nn)
: n(nn)
{ }

constant::evaluate()
{
  return n;
}
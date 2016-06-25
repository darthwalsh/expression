#include "binaryop.hpp"

binaryop::binaryop(expression* l, expression* r)
  : left(l), right(r)
  { }

binaryop::~binaryop()
{
  delete left;
  delete right;
}
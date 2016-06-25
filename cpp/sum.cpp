#include "sum.hpp"

sum::sum(expression* left, expression* right)
: binaryop(left, right)
{ }

int sum::evaluate()
{
  return left->evaluate() + right->evaluate();
}
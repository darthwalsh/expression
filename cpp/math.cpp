#include "math.hpp"

sum::sum(expression* left, expression* right)
: binaryop(left, right)
{ }

int sum::evaluate()
{
  return left->evaluate() + right->evaluate();
}

difference::difference(expression* left, expression* right)
: binaryop(left, right)
{ }

int difference::evaluate()
{
  return left->evaluate() - right->evaluate();
}

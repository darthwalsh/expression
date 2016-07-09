#include <cmath>

#include "math.hpp"

int sum::evaluate()
{
  return left->evaluate() + right->evaluate();
}

int difference::evaluate()
{
  return left->evaluate() - right->evaluate();
}

int product::evaluate()
{
  return left->evaluate() * right->evaluate();
}

int quotient::evaluate()
{
  return left->evaluate() / right->evaluate();
}

int modulo::evaluate()
{
  return left->evaluate() % right->evaluate();
}

int power::evaluate()
{
  return (int)pow(left->evaluate(), right->evaluate());
}


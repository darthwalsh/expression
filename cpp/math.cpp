#include <cmath>

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


product::product(expression* left, expression* right)
: binaryop(left, right)
{ }

int product::evaluate()
{
  return left->evaluate() * right->evaluate();
}


quotient::quotient(expression* left, expression* right)
: binaryop(left, right)
{ }

int quotient::evaluate()
{
  return left->evaluate() / right->evaluate();
}


modulo::modulo(expression* left, expression* right)
: binaryop(left, right)
{ }

int modulo::evaluate()
{
  return left->evaluate() % right->evaluate();
}


power::power(expression* left, expression* right)
: binaryop(left, right)
{ }

int power::evaluate()
{
  return (int)pow(left->evaluate(), right->evaluate());
}


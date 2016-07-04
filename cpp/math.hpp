#pragma once

#include "binaryop.hpp"

class sum : public binaryop {
  public:
  sum(expression* left, expression* right);
  int evaluate() override;
};

class difference : public binaryop {
  public:
  difference(expression* left, expression* right);
  int evaluate() override;
};

class product : public binaryop {
  public:
  product(expression* left, expression* right);
  int evaluate() override;
};

class quotient : public binaryop {
  public:
  quotient(expression* left, expression* right);
  int evaluate() override;
};

class modulo : public binaryop {
  public:
  modulo(expression* left, expression* right);
  int evaluate() override;
};

class power : public binaryop {
  public:
  power(expression* left, expression* right);
  int evaluate() override;
};

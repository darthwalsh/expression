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

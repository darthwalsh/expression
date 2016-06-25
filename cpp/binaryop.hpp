#pragma once

#include "expression.hpp"

class binaryop : public expression {
  public:
  binaryop(expression* left, expression* right);
  virtual ~binaryop();

  private:
  binaryop(const binaryop& other);
  operator=(const binaryop& other);

  protected:
  expression* left;
  expression* right;
};

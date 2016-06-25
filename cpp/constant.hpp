#pragma once

#include "expression.hpp"

class constant : public expression {
  public:
  constant(int n);
  virtual int evaluate() override;

  private:
  int n;
};

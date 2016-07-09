#pragma once

#include "binaryop.hpp"

class sum : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

class difference : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

class product : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

class quotient : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

class modulo : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

class power : public binaryop {
  public:
  using binaryop::binaryop;
  int evaluate() override;
};

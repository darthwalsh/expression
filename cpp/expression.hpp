#pragma once

class expression {
  public:
  virtual int evaluate() = 0;
  virtual ~expression() = 0;
};
#pragma once

#include "expression.h"

typedef struct {
  expression base;
  int n;
} constant;

void constant_ctor(constant* this, int n);
int contant_evaluate(constant*);

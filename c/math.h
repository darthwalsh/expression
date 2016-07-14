#pragma once

#include "expression.h"

typedef struct {
  expression base;
  expression* left;
  expression* right;
} binaryop;

void binaryop_ctor(binaryop* this, expression* left, expression* right);
void binaryop_delete(binaryop* this);

typedef struct {
  binaryop base;
} sum;

void sum_ctor(sum* this, expression* left, expression* right);
int sum_evaluate(sum*);

typedef struct {
  binaryop base;
} difference;

void difference_ctor(difference* this, expression* left, expression* right);
int difference_evaluate(difference*);

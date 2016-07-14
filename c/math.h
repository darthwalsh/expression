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

typedef struct {
  binaryop base;
} product;

void product_ctor(product* this, expression* left, expression* right);
int product_evaluate(product*);

typedef struct {
  binaryop base;
} quotient;

void quotient_ctor(quotient* this, expression* left, expression* right);
int quotient_evaluate(quotient*);

typedef struct {
  binaryop base;
} modulo;

void modulo_ctor(modulo* this, expression* left, expression* right);
int modulo_evaluate(modulo*);

typedef struct {
  binaryop base;
} power;

void power_ctor(power* this, expression* left, expression* right);
int power_evaluate(power*);

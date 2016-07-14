#include <stdlib.h>
#include <math.h>

#include "math.h"

expression_vtable binaryop_table = { 
  0,
  (void (*)(expression*))&binaryop_delete
};

void binaryop_ctor(binaryop* this, expression* left, expression* right) {
  this->base.vtable = binaryop_table;
  this->left = left;
  this->right = right;  
}

void binaryop_delete(binaryop* this) {
  delete(this->left);
  delete(this->right);
  free(this);
}


expression_vtable sum_table = { 
  (int (*)(expression*))&sum_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void sum_ctor(sum* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = sum_table;
}

int sum_evaluate(sum* this) {
  return evaluate(this->base.left) + evaluate(this->base.right);
}


expression_vtable difference_table = { 
  (int (*)(expression*))&difference_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void difference_ctor(difference* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = difference_table;
}

int difference_evaluate(difference* this) {
  return evaluate(this->base.left) - evaluate(this->base.right);
}


expression_vtable product_table = { 
  (int (*)(expression*))&product_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void product_ctor(product* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = product_table;
}

int product_evaluate(product* this) {
  return evaluate(this->base.left) * evaluate(this->base.right);
}


expression_vtable quotient_table = { 
  (int (*)(expression*))&quotient_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void quotient_ctor(quotient* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = quotient_table;
}

int quotient_evaluate(quotient* this) {
  return evaluate(this->base.left) / evaluate(this->base.right);
}


expression_vtable modulo_table = { 
  (int (*)(expression*))&modulo_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void modulo_ctor(modulo* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = modulo_table;
}

int modulo_evaluate(modulo* this) {
  return evaluate(this->base.left) % evaluate(this->base.right);
}


expression_vtable power_table = { 
  (int (*)(expression*))&power_evaluate,
  (void (*)(expression*))&binaryop_delete
};

void power_ctor(power* this, expression* left, expression* right) {
  binaryop_ctor((binaryop*)this, left, right);
  this->base.base.vtable = power_table;
}

int power_evaluate(power* this) {
  return (int)pow(evaluate(this->base.left), evaluate(this->base.right));
}

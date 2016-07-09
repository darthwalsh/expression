#include <stdlib.h>

#include "constant.h"

expression_vtable constant_table = { 
  (int (*)(expression*))&contant_evaluate,
  (void (*)(expression*))&free
};

void constant_ctor(constant* this, int n) {
  this->base.vtable = constant_table;
  this->n = n;
}

int contant_evaluate(constant* this) {
  return this->n;
}
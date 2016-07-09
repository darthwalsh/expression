#include "expression.h"

int evaluate(expression* this) {
  return this->vtable.evaluate(this);
}

void delete(expression* this) {
  this->vtable.delete(this);
}
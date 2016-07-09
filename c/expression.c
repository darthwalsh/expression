#include "expression.h"

int evaluate(expression* this) {
  return this->vtable.evaluate(this);
}
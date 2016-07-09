#include <stdlib.h>
#include <stdio.h>

#include "expression.h"
#include "constant.h"
#include "math.h"

// http://stackoverflow.com/questions/3113583/how-could-one-implement-c-virtual-functions-in-c
// http://stackoverflow.com/questions/415452/object-orientation-in-c
// http://stackoverflow.com/questions/351733/can-you-write-object-oriented-code-in-c

int main() {
  constant* c1 = malloc(sizeof(constant));
  constant_ctor(c1, 1);

  constant* c2 = malloc(sizeof(constant));
  constant_ctor(c2, 2);

  sum* s = malloc(sizeof(sum));
  sum_ctor(s, (expression*)c1, (expression*)c2);

  printf("evaluate: %d\r\n", evaluate((expression*)s));

  delete((expression*)s);
}
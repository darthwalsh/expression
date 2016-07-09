#include <stdio.h>

#include "constant.h"
#include "math.h"

int main() {
  constant c1;
  constant_ctor(&c1, 1);

  constant c2;
  constant_ctor(&c2, 2);

  sum s;
  sum_ctor(&s, (expression*)&c1, (expression*)&c2);

  printf("evaluate: %d\r\n", evaluate((expression*)&s));
}
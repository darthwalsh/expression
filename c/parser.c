#include <stdlib.h>

#include "parser.h"
#include "constant.h"
#include "math.h"

expression* parseHelper(char** ps) {
  while (**ps == ' ') {
    ++(*ps);
  }

  char current = **ps;
  
  switch (current) {
    case '+': ;
      ++(*ps);
      expression* left = parseHelper(ps);
      expression* right = parseHelper(ps);
      sum* s = malloc(sizeof(sum));
      sum_ctor(s, left, right);
      return (expression*)s;
  }

  constant* c = malloc(sizeof(constant));
  constant_ctor(c, atoi(*ps));  
  ++(*ps);

  while ('0' <= **ps && **ps <= '9') {
    ++(*ps);
  }

  return (expression*)c; 
}

expression* parse(char* s) {
  expression* e = parseHelper(&s);
  if (*s != '\0') {
    return 0;
  }
  return e;
}

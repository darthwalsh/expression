#include <stdlib.h>

#include "parser.h"
#include "constant.h"
#include "math.h"

expression* parseHelper(char** ps) {
  while (**ps == ' ') {
    ++(*ps);
  }

  char* s = *ps;
  char current = *s;
  
  // Avoid parsing negative number as a subtraction
  if (!(current == '-' && s[1] != ' ')) {
    switch (current) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
        ++(*ps);
        expression* left = parseHelper(ps);
        expression* right = parseHelper(ps);

        switch (current) {
          case '+': {
            sum* e = malloc(sizeof(sum));
            sum_ctor(e, left, right);
            return (expression*)e;
          }
          case '-': {
            difference* e = malloc(sizeof(difference));
            difference_ctor(e, left, right);
            return (expression*)e;
          }
          case '*': {
            product* e = malloc(sizeof(product));
            product_ctor(e, left, right);
            return (expression*)e;
          }
          case '/': {
            quotient* e = malloc(sizeof(quotient));
            quotient_ctor(e, left, right);
            return (expression*)e;
          }
          case '%': {
            modulo* e = malloc(sizeof(modulo));
            modulo_ctor(e, left, right);
            return (expression*)e;
          }
          case '^': {
            power* e = malloc(sizeof(power));
            power_ctor(e, left, right);
            return (expression*)e;
          }
        }
    }
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

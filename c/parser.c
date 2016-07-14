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
        ++(*ps);
        expression* left = parseHelper(ps);
        expression* right = parseHelper(ps);

        switch (current) {
          case '+': {
            sum* s = malloc(sizeof(sum));
            sum_ctor(s, left, right);
            return (expression*)s;
          }
          case '-': {
            difference* d = malloc(sizeof(difference));
            difference_ctor(d, left, right);
            return (expression*)d;
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

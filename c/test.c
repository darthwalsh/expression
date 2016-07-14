#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"
#include "constant.h"
#include "math.h"
#include "parser.h"

// http://stackoverflow.com/questions/3113583/how-could-one-implement-c-virtual-functions-in-c
// http://stackoverflow.com/questions/415452/object-orientation-in-c
// http://stackoverflow.com/questions/351733/can-you-write-object-oriented-code-in-c

int mainTestSum() {
  constant* c1 = malloc(sizeof(constant));
  constant_ctor(c1, 1);

  constant* c2 = malloc(sizeof(constant));
  constant_ctor(c2, 2);

  sum* s = malloc(sizeof(sum));
  sum_ctor(s, (expression*)c1, (expression*)c2);

  printf("evaluate: %d\r\n", evaluate((expression*)s));

  delete((expression*)s);
  return 0;
}

int main() {
  FILE* file = fopen("..\\test.txt", "r");

  char line[256];
  while(fgets(line, sizeof(line), file)) {
    size_t length = strlen(line);
    if (*line && line[length - 1] == '\n') {
      line[length - 1] = '\0';
    }
    printf("%s   ", line);

    expression* e = parse(line);
    if (e == NULL) {
      printf("Couldn't parse\r\n");
      exit(1);
    }

    int actual = evaluate(e);

    fgets(line, sizeof(line), file);
    int expected = atoi(line+1);

    if (actual != expected) {
      printf("actual %d != expected %d\r\n", actual, expected);
      exit(1);
    }
    
    printf("= %d\r\n", actual);

    fgets(line, sizeof(line), file);
  }

  fclose(file);
  return 0;
}
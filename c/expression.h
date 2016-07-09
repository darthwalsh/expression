#pragma once

struct expression;

typedef struct {
  int (*evaluate)(struct expression*);
  void (*delete)(struct expression*);
} expression_vtable;

typedef struct expression {
  expression_vtable vtable;
} expression;

int evaluate(expression* this);
void delete(expression* this);

#ifndef LIST_H
#define LIST_H

#include "lista_linear_sequencial_estatica_circular.h"

typedef struct
{
      int max;
      int first;
      int last;
      int count;
      //privado
      list *_list;
} stack;

stack *new_stack(int size);
void clear(stack *s);
void push(int x, stack *s);
int pop(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
int is_null(stack *s);
//Destroi a pilha e torna o ponteiro nulo
void destroy_list(stack **s);

#endif
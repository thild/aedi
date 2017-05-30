#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lista_linear_sequencial_estatica_circular.h"

#define DEBUG 1

stack *new_stack(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->_list = (list *)malloc(size * sizeof(list));
    s->count = 0;
    s->first = -1;
    s->last = -1;
    s->max = size;
    return s;
}

//Insere um elemento na primeira posição
void push(int x, stack *s)
{
    if (is_null(s))
        return;
    insert_at(x, 0, s->_list);
}

//Remove o primeiro elemento e o retorna
int pop(stack *s)
{
    if (is_null(l))
        return -1;
    return remove_at(0, s->_list);
}

int is_null(stack *s)
{
    return s == NULL;
}

void clear(stack *s)
{
    if (is_null(s))
        return;
    s->_l->count = 0;
    s->_l->first = -1;
    s->_l->last = -1;
}

int is_empty(stack *s)
{
    return is_null(s) || s->count == 0;
}

int is_full(stack *s)
{
    return s->count == s->max;
}

void destroy_stack(stack **s)
{
    free((*s)->_list);
    free(*s);
    *s = NULL;
}

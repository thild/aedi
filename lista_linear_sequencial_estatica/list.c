#include <stdlib.h>
#include <stdio.h>
#include "list.h"


list* new_list(int size) {
    list *l = (list*) malloc(sizeof(list));
    l->items = (int*) malloc(size * sizeof(int));
    l->count = 0;
    l->first = -1;
    l->last = -1;
    l->max = size;
    return l;
}

int is_null(list *l) {
    return l == NULL;
}

void clear(list *l) {
    if (is_null(l)) return;
    l->count = 0;
    l->first = -1;
    l->last = -1;
}

// list.c
void insert(int x, list *l) {
    if (is_null(l) || is_full(l)) return;
    if(is_empty(l)) {
        l->first = 0;
    }
    l->last++;
    l->items[l->last] = x;
    l->count++;
}

int remove_at(int i, list *l) {
    if (is_null(l) || 
        is_empty(l) || 
        (i < 0 || i > l->last)) return -1;
    int x = l->items[i];
    for (int j = i; j < l->last; j++)
    {
        l->items[j] = l->items[j+1];
    }
    l->last--;
    l->count--;
    if (is_empty(l)) {
        l->first = -1;
    }
    return x;
}

int is_empty(list *l) {
    return is_null(l) || l->count == 0;
}

int is_full(list *l) {
    return l->count == l->max;
}

void print(list *l) {
    for (int i = 0; i < l->count; i++)
    {
        printf("Item[%d] = %d\n", i, l->items[i]);
    }
}

void destroy_list(list **l) {
    free((*l)->items);
    free(*l);
    *l = NULL;
}


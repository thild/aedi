#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada_simples.h"

#define DEBUG 1

linked_list *new_linked_list(int size)
{
    linked_list *l = (linked_list *)malloc(sizeof(linked_list));
    l->count = 0;
    l->max = size;
    l->first = NULL;
    return l;
}

int is_empty(linked_list *l)
{
    return l == NULL || l->first == NULL;
}

int is_full(linked_list *l)
{
    return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

void insert_first(int x, linked_list *l)
{
    if (l == NULL || is_full(l))
        return;
    node *new_node = create_node(x);
    if (is_empty(l))
    {
        l->first = new_node;
    }
    else
    {
        new_node->next = l->first;
        l->first = new_node;
    }
    l->count++;
}

node *create_node(int x)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = x;
    new_node->next = NULL;
    return new_node;
}

void print(linked_list *l)
{
    if (is_empty(l))
        return;
    node *aux = l->first;
    while (aux != NULL)
    {
        printf("%d\n", aux->value);
        aux = aux->next;
    }
}

void destroy_linked_list(linked_list **l)
{
    if (is_empty(*l)) return;
    node *aux = (*l)->first;
    while (aux != NULL)
    {
        node *del = aux;
        aux = aux->next;
        free(del);
    }
    free (*l);
    *l = NULL;
}

#include <stdlib.h>
#include <stdio.h>
#include "lista_linear_sequencial_estatica_circular.h"

#define DEBUG 1

list *new_list(int size)
{
    debug_print("");
    list *l = (list *)malloc(sizeof(list));
    l->items = (int *)malloc(size * sizeof(int));
    l->count = 0;
    l->first = -1;
    l->last = -1;
    l->max = size;
    return l;
}

int is_null(list *l)
{
    return l == NULL;
}

void clear(list *l)
{
    if (is_null(l))
        return;
    l->count = 0;
    l->first = -1;
    l->last = -1;
}

//Remove o primeiro elemento e o retorna
int remove_first(list *l)
{
    if (is_null(l))
        return -1;
    return remove_at(0, l);
}

//Remove o último elemento e o retorna
int remove_last(list *l)
{
    if (is_null(l))
        return -1;
    return remove_at(l->count - 1, l);
}

int remove_at(int i, list *l)
{
    if (is_null(l) ||
        is_empty(l) ||
        (i < 0 || i > l->count - 1))
        return -1;

    //devemos mapear o i lógico para o i físico
    i = (l->first + i) % l->max;

    int x = l->items[i]; //item que será retornado

    //se tiver apenas um item a lista deve ser resetada
    if (l->count == 1)
    {
        clear(l);
        return x;
    }

    if (i == l->first)
    {
        int j = position(REMOVE_FIRST, l);
        l->first = j;
    }
    else if (i == l->last)
    {
        int j = position(REMOVE_LAST, l);
        l->last = j;
    }
    else
    {
        int j = i;
        while (j != l->last)
        {
            if (j == l->max - 1) //quando cruza o 0
            {
                l->items[j] = l->items[0];
                j = 0;
            }
            else
            {
                l->items[j] = l->items[j + 1];
                ++j;
            }
        }
        l->last = l->last == 0 ? l->max - 1 : l->last - 1;
    }
    l->count--;
    return x;
}

int is_empty(list *l)
{
    return is_null(l) || l->count == 0;
}

int is_full(list *l)
{
    return l->count == l->max;
}

void destroy_list(list **l)
{
    free((*l)->items);
    free(*l);
    *l = NULL;
}

//Insere um elemento na primeira posição
void insert_first(int x, list *l)
{
    if (is_null(l))
        return;
    insert_at(x, 0, l);
}

// list.c
void insert_last(int x, list *l)
{
    if (is_null(l))
        return;
    if (is_empty(l))
        insert_at(x, 0, l);
    else
        insert_at(x, l->count, l);
}

//Insere o elemento x na posição lógica i.
void insert_at(int x, int i, list *l)
{
    //se a lista for nula ou estiver cheia nao é possivel inserir
    if (is_null(l) ||
        is_full(l))
        return;

    //condicao especial quando a lista é vazia
    if (is_empty(l) && i == 0)
    {
        l->items[0] = x;
        l->first = 0;
        l->last = 0;
        l->count = 1;
        return;
    }

    //se a lista nao estiver vazia,
    //nao eh possivel inserir fora do intervalo da lista
    if (i < 0 || (i > l->count))
    {
        return;
    }

    //devemos mapear o i lógico para o i físico
    i = (l->first + i) % l->max;

    if (i == l->first)
    {
        int j = position(INSERT_FIRST, l);
        l->first = j;
        l->items[j] = x;
    }
    else if (i == l->last)
    {
        int j = position(INSERT_LAST, l);
        l->last = j;
        l->items[j] = x;
    }
    else // inserindo no meio da lista
    {
        int j; // j deve começar em last + 1
        if (l->last == l->max - 1)
            j = 0;
        else
            j = l->last + 1;
        while (j != i)
        {
            if (j == 0)
            {
                l->items[j] = l->items[l->max - 1];
                j = l->max - 1;
            }
            else
            {
                l->items[j] = l->items[j - 1];
                --j;
            }
        }

        l->last = l->last == l->max - 1 ? 0 : l->last + 1;
        l->items[i] = x;
    }
    l->count++;
}

//Procura por um elemento e retorna sua posição
int search(int x, list *l)
{
    if (is_null(l) || is_empty(l))
        return -1;

    if (l->first > l->last)
    {
        for (int i = l->first; i < l->max - 1; i++)
        {
            if (x == l->items[i])
                return i;
        }
        for (int i = 0; i < l->last; i++)
        {
            if (x == l->items[i])
                return i;
        }
    }
    else
    {
        for (int i = l->first; i < l->last; i++)
        {
            if (x == l->items[i])
                return i;
        }
    }
    return -1;
}

static int position(operation_t op, list *l)
{
    switch (op)
    {
    case INSERT_FIRST:
        if (l->first == -1)
            return 0;
        if (l->first == 0)
            return l->max - 1;
        return l->first - 1;
        break;
    case INSERT_LAST:
        if (l->last == -1)
            return 0;
        if (l->last == l->max - 1)
            return 0;
        return l->last + 1;
        break;
    case REMOVE_FIRST:
        if (l->first == -1)
            return -1;
        if (l->first == l->max - 1)
            return 0;
        return l->first + 1;
        break;
    case REMOVE_LAST:
        if (l->last == -1)
            return -1;
        if (l->last == 0)
            return l->max - 1;
        return l->last - 1;
        break;
    default:
        return -1;
        break;
    }
}

void print(list *l)
{

    printf("Representação lógica da lista:\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("+-----");
    }
    printf("+\n");
    printf("|%-5s", "VIRT.");

    for (int i = 0; i <= l->max - 1; i++)
    {
        int j = (l->first + i) % l->max;
        if (i >= l->count)
        {
            printf("|%-5s", "LIXO");
        }
        else
        {
            printf("|%-5d", l->items[j]);
        }
    }

    printf("|\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("+-----");
    }
    printf("+\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("%4d%s", i, "  ");
    }
    printf("\n");
    int fp, lp;

    if (is_empty(l))
    {
        fp = 5;
        lp = 5;
    }
    else
    {
        fp = 11;
        lp = ((l->count) * 7 - (l->count)) + 5;
    }
    printf("%*s", fp, "|\n");
    printf("%*s", fp, "f\n");
    printf("%*s", lp, "|\n");
    printf("%*s", lp, "l\n");
    printf("\n");

    //Fim representação na lista

    printf("Representação em memória da lista:\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("+-----");
    }
    printf("+\n");
    printf("|%-5s", "VIRT.");
    int last = l->count - 1;
    for (int i = 0; i < l->max; i++)
    {
        int j = (l->max - l->first + i) % l->max;

        if (j > last)
        {
            printf("|%-5s", "LIXO");
        }
        else
        {
            printf("|%-5d", l->items[i]);
        }
    }
    printf("|\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("+-----");
    }

    printf("+\n");
    for (int i = -1; i < l->max; i++)
    {
        printf("%4d%s", i, "  ");
    }
    printf("\n");
    if (is_empty(l))
    {
        fp = 5;
        lp = 5;
    }
    else
    {
        fp = ((l->first + 1) * 7 - (l->first + 1)) + 5;
        lp = ((l->last + 1) * 7 - (l->last + 1)) + 5;
    }
    printf("%*s", fp, "|\n");
    printf("%*s", fp, "f\n");
    printf("%*s", lp, "|\n");
    printf("%*s", lp, "l\n");
    printf("First: %d; Last: %d; Count: %d; Max: %d;\n",
           l->first, l->last, l->count, l->max);
    printf("--------------------------------------------------------\n\n");

    //Fim representação em memória

   
}
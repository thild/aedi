#include <stdlib.h>
#include <stdio.h>
#include "matriz_esparsa.h"

sparse_matrix *new_sparce_matrix(int m, int n)
{
    sparse_matrix *a = (sparse_matrix *)malloc(sizeof(sparse_matrix));
    a->m = m;
    a->n = n;
    a->first = (node *)malloc(sizeof(node));
    a->first->value = -1;
    a->first->i = -1;
    a->first->j = -1;
    a->first->right = a->first;
    a->first->down = a->first;
    return a;
}

void print_sparse_matrix(sparse_matrix *a)
{
    if (a == NULL)
        return;

    node *first = a->first;
    node *rnode = first, *dnode = first;

    for (int i = -1; i < a->m; ++i)
    {
        for (int j = -1; j < a->n; ++j)
        {
            if (dnode != NULL && rnode != NULL && dnode->i == i && rnode->j == j)
            {
                printf("(%-2d,%2d)=%-5d", i, j, rnode->value);
                rnode = rnode->right;
            }
            else
            {
               printf("(%-2d,%2d)=%-5d", i, j, i == -1 || j == -1 ? -1 : 0);
            }
        }
        printf("\n");
        if (dnode != NULL && dnode->i == i)
        {
            dnode = dnode->down;
            rnode = dnode;
        }
    }
}

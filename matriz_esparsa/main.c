#include <stdlib.h>
#include <stdio.h>
#include "matriz_esparsa.h"

int main()
{
    sparse_matrix *a = new_sparce_matrix(10, 10);

    node *d = (node *)malloc(sizeof(node));
    d->i = 5;
    d->j = -1;
    d->value = -1;
    a->first->down = d;

    node *r = (node *)malloc(sizeof(node));
    r->i = -1;
    r->j = 3;
    r->value = -1;
    a->first->right = r;

    node *n = (node *)malloc(sizeof(node));
    n->i = 5;
    n->j = 3;
    n->value = 15;
    n->down = r;
    n->right = d;

    d->right = n;
    r->down = n;

    print_sparse_matrix(a);

    return EXIT_SUCCESS;
}

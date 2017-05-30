#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct Node
{
    int value, i, j;
    struct Node *right;
    struct Node *down;
} node;

typedef struct
{
    node *first;
    int m;
    int n;
} sparse_matrix;

sparse_matrix *new_sparce_matrix(int m, int n);
void print_sparse_matrix(sparse_matrix *a);

#endif
/*
The MIT License (MIT)
copyright © 2015 <copyright holders>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
documentation files (the “Software”), to deal in the Software without restriction, including without 
limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
the Software, and to permit persons to whom the Software is furnished to do so, subject to the following
conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions 
of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT 
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN 
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
OR OTHER DEALINGS IN THE SOFTWARE.
*/


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

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

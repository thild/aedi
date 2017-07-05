#include <stdlib.h>
#include <stdio.h>
#include "lista_linear_sequencial_estatica_circular.h"

int ultimo(list *l);
void mprint(list *l);

int ultimo(list *l)
{
    int a = 0;
    int j = 0;
    int k = 3;
    int n = l->count;

    //[14, 31, 42, 159, 117, 101, 130, 82, 113, 4]
    //[31, 42, 117, 101, 82, 113]
    //[42, 117, 82, 113]
    //[42, 82, 113]
    //[42, 113]
    //[113]

    for (int i = 0; i < n; ++i)
    {
        j = (l->count - 1) - (a % l->count);
        remove_at(j, l);
        a = (a + k) % n - 1;
        if (a > l->count)
        {
            a = a % l->count;
        }
        printf("%d %d\n", a, l->count);
        mprint(l);
    }
    return l->items[l->first];

}

void main()
{
    list *l = new_list(10);

    insert_last(14, l);
    insert_last(31, l);
    insert_last(42, l);
    insert_last(159, l);
    insert_last(117, l);
    insert_last(101, l);
    insert_last(130, l);
    insert_last(82, l);
    insert_last(113, l);
    insert_last(4, l);
    //print(l);
    ultimo(l);
    //print(l);

    // l->first = 1;
    // l->last = 3;
    // l->count = 3;
    // l->items[1] = 5;
    // l->items[2] = 10;
    // l->items[3] = 15;
    // print(l);
    // printf("insert_at(100, 3, l)\n");
    // insert_at(100, 3, l);
    // print(l);
    // printf("insert_at(200, 4, l)\n");
    // insert_at(200, 4, l);
    // print(l);
    // printf("insert_last(10, l)\n");
    // insert_last(10, l);
    // print(l);
    // printf("insert_first(20, l)\n");
    // insert_first(20, l);
    // print(l);
    // printf("insert_first(30, l)\n");
    // insert_first(30, l);
    // print(l);
    // printf("remove_at(3,l) %d\n", remove_at(3, l));
    // print(l);
    // printf("remove_last(l) %d\n", remove_last(l));
    // print(l);
    // printf("remove_at(0,l) %d\n", remove_at(0, l));
    // print(l);
    // printf("insert_last(10, l)\n");
    // insert_last(10, l);
    // print(l);
    // insert_last(20, l);
    // printf("insert_last(20, l)\n");
    // print(l);
    // // insert_last(30, l);
    // // printf("insert_last(30, l)\n");
    // // print(l);
    // // insert_last(40, l);
    // // printf("insert_last(40, l)\n");
    // // print(l);
    // // remove_first(l);
    // // printf("remove_first(l)\n");
    // // print(l);
    // // insert_at(10, 2, l);
    // // printf("insert_at(10, 2, l)\n");
    // // print(l);
    // // insert_at(20, 10, l);
    // // printf("insert_at(20, 10, l)\n");
    // // print(l);
    // // remove_first(l);
    // // printf("remove_first(l)\n");
    // // print(l);
    // // remove_last(l);
    // // printf("remove_last(l)\n");
    // // print(l);
    // // insert_at(20, 1, l);
    // // insert_at(40, 1, l);
    // // insert_first(50, l);
    // // insert_first(100, l);
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}

void mprint(list *l)
{

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

    //Fim representação em memória
}
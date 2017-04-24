#include <stdlib.h>
#include <stdio.h>
#include "lista_linear_sequencial_estatica_circular.h"

void main()
{
    list *l = new_list(10);
    l->first = 1;
    l->last = 3;
    l->count = 3;
    l->items[1] = 5;
    l->items[2] = 10;
    l->items[3] = 15;
    print(l);
    printf("insert_at(100, 3, l)\n");
    insert_at(100, 3, l);
    print(l);
    printf("insert_at(200, 4, l)\n");
    insert_at(200, 4, l);
    print(l);
    printf("insert_last(10, l)\n");
    insert_last(10, l);
    print(l);
    printf("insert_first(20, l)\n");
    insert_first(20, l);
    print(l);
    printf("insert_first(30, l)\n");
    insert_first(30, l);
    print(l);
    printf("remove_at(3,l) %d\n", remove_at(3, l));
    print(l);
    printf("remove_last(l) %d\n", remove_last(l));
    print(l);
    printf("remove_at(0,l) %d\n", remove_at(0, l));
    print(l);
    printf("insert_last(10, l)\n");
    insert_last(10, l);
    print(l);
    insert_last(20, l);
    printf("insert_last(20, l)\n");
    print(l);
    // insert_last(30, l);
    // printf("insert_last(30, l)\n");
    // print(l);
    // insert_last(40, l);
    // printf("insert_last(40, l)\n");
    // print(l);
    // remove_first(l);
    // printf("remove_first(l)\n");
    // print(l);
    // insert_at(10, 2, l);
    // printf("insert_at(10, 2, l)\n");
    // print(l);
    // insert_at(20, 10, l);
    // printf("insert_at(20, 10, l)\n");
    // print(l);
    // remove_first(l);
    // printf("remove_first(l)\n");
    // print(l);
    // remove_last(l);
    // printf("remove_last(l)\n");
    // print(l);
    // insert_at(20, 1, l);
    // insert_at(40, 1, l);
    // insert_first(50, l);
    // insert_first(100, l);
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}

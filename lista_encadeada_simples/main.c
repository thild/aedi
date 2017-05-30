#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada_simples.h"

void main()
{
    linked_list *l = new_linked_list(-1);
    insert_first(10, l);
    insert_first(20, l);
    insert_first(30, l);
    insert_first(40, l);
    print(l);
    // insert_first(10, l);
    // insert_first(20, l);
    // insert_first(30, l);
    // insert_first(40, l);
    // printf("Inserindo 10\n");
    // print(l);
    destroy_linked_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}

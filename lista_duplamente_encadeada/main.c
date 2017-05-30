#include <stdlib.h>
#include <stdio.h>
#include "lista_duplamente_encadeada.h"

void my_print(node *current) {
    printf("my_print %d\n", current->value);
}

int main()
{
    linked_list *l = new_linked_list(-1);
    insert_first(10, l);
    insert_first(20, l);
    insert_first(30, l);
    insert_first(40, l);
    print(l);
    insert_last(100, l);
    insert_last(200, l);
    print(l);
    printf("Removendo a última posição:");
    printf("%d\n", remove_last(l));
    print(l);
    walk(l, &my_print);
    // insert_first(10, l);
    // insert_first(20, l);
    // insert_first(30, l);
    // insert_first(40, l);
    // printf("Inserindo 10\n");
    // print(l);
    destroy_linked_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
    return EXIT_SUCCESS;
}

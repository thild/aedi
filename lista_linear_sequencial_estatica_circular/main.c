#include <stdlib.h>
#include <stdio.h>
#include "lista_linear_sequencial_estatica_circular.h"

void main() {
    list *l = new_list(5);
    insert_at(10, 0, l);
    insert_at(20, 1, l);
    insert_at(30, 0, l);
    insert_at(40, 2, l);
    insert_at(50, 3, l);
    print(l);
    printf("First: %d; Last: %d;\n", l->first, l->last);
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}

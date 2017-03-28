#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void main() {
    list *l = new_list(10);
    insert(0, l);
    insert(10, l);
    insert(20, l);
    insert(30, l);
    insert(40, l);
    insert(50, l);
    print(l);
    printf("Item %d removido.\n", remove_at(2, l));
    print(l);
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers?\n%d", l == NULL);
}

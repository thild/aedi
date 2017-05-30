#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
      int value;
      struct Node *next;
      struct Node *previous;
} node;

typedef struct
{
      node *first;
      node *last;
      int count;
      int max;
} linked_list;

linked_list *new_linked_list(int size);
node *create_node(int x);
void clear(linked_list *l);
void insert_last(int x, linked_list *l);
int remove_at(int i, linked_list *l);
int is_empty(linked_list *l);
int is_full(linked_list *l);
void print(linked_list *l);

//Destroi a linked_lista e torna o ponteiro nulo
void destroy_linked_list(linked_list **l);

//Remove o último elemento e o retorna
int remove_last(linked_list *l);

//Remove o primeiro elemento e o retorna
int remove_first(linked_list *l);

//Insere o elemento x na posição i
void insert_at(int x, int i, linked_list *l);

//Insere um elemento na primeira posição
void insert_first(int x, linked_list *l);

//Procura por um elemento e retorna sua posição
int search(int x, linked_list *l);

void walk (linked_list *l, void (*f)(node*));

#endif
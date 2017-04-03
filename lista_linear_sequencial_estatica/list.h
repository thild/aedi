#ifndef LIST_H
#define LIST_H

typedef struct {
      int *items;
      int max;
      int first;
      int last;
      int count;
} list;

list* new_list(int size);
void clear(list *l);
<<<<<<< HEAD
void insert(int x, list *l);
=======
void insert_last(int x, list *l);
>>>>>>> Implementação Unidade 3 - Atividade 1 - Complementando a lista linear
int remove_at(int i, list *l);
int is_empty(list *l);
int is_full(list *l);
void print(list *l);

//Destroi a lista e torna o ponteiro nulo
void destroy_list(list **l);

//Remove o último elemento e o retorna
int remove_last(list *l);

//Remove o primeiro elemento e o retorna
int remove_first(list *l);

//Insere um elemento na primeira posição
void insert_first(int x, list *l);

//Procura por um elemento e retorna sua posição
int search(int x, list *l);

<<<<<<< HEAD
=======
//Insere o elemento x na posição i
void insert_at(int x, int i, list *l);
>>>>>>> Implementação Unidade 3 - Atividade 1 - Complementando a lista linear


#endif
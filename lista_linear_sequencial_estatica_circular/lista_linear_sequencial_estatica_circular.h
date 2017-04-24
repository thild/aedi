#ifndef LIST_H
#define LIST_H

#define debug_print(...)                                                 \
      do                                                                 \
      {                                                                  \
            if (DEBUG)                                                   \
            {                                                            \
                  printf("%s (%s)\n", __PRETTY_FUNCTION__, __VA_ARGS__); \
            }                                                            \
      } while (0)

//fprintf(stderr, __VA_ARGS__);

typedef enum { INSERT_FIRST,
               INSERT_LAST,
               REMOVE_FIRST,
               REMOVE_LAST } operation_t;

typedef struct
{
      int *items;
      int max;
      int first;
      int last;
      int count;
} list;

list *new_list(int size);
void clear(list *l);
void insert_last(int x, list *l);
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

//Insere o elemento x na posição i
void insert_at(int x, int i, list *l);

//Insere um elemento na primeira posição
void insert_first(int x, list *l);

//Procura por um elemento e retorna sua posição
int search(int x, list *l);

//Retorna a próxima posição a ser
static int position(operation_t op, list *l);

#endif
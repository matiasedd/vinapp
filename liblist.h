#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

struct node
{
    char *filename;
    char *content;
    struct stat st;

    struct node *next;
    struct node *prev;
};

typedef struct node node_t;

struct list
{
    int size;
    node_t *head;
    node_t *tail;
};

typedef struct list list_t;

/*
 * Responsável por instanciar uma nova lista
 * Não possui parâmetros
 * Retorna um ponteiro para a lista instanciada
 */
list_t *create_list(void);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 * Retorna nulo
 */
list_t *free_list(list_t *list);

/*
 * Responsável por instanciar um novo nó
 * Recebe como parâmetro o nome do arquivo
 * Retorna um ponteiro para o nó instanciado
 */
node_t *create_node(char *filename);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 */
int insert_node(list_t *list, node_t *node);

/*
 * Responsável por liberar a memória alocada para o nó
 * Recebe como parâmetro um ponteiro para o nó
 */
int remove_node(list_t *list, node_t *node);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 */
node_t *find_node(list_t *list, char *filename);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 */
void print_list(list_t *list);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 */
int insert_file(list_t *list, char *filename, int counter, int size);

/*
 * Responsável por liberar a memória alocada para a lista
 * Recebe como parâmetro um ponteiro para a lista
 */
int remove_file(list_t *list, char *filename, int counter, int size);

/*
 * Responsável por escrever o conteúdo da lista em um arquivo
 * Recebe como parâmetro um ponteiro para a lista e o nome do arquivo
 * Não possui retorno
 */
void write_file(list_t *list, char *filename);

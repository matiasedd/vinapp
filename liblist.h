#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <sys/stat.h>

#define BUFFER_SIZE 32

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

list_t *create_list(void);

list_t *free_list(list_t *list);

node_t *create_node(char *filename);

node_t *find_node(list_t *list, char *filename);

int insert_node(list_t *list, node_t *node);

int remove_node(list_t *list, node_t *node);

void print_list(list_t *list);

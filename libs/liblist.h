#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
    char *name;
    struct node *next;
};

struct linked_list {
    int size;
    struct node *head;
    struct node *tail;
};

typedef struct node node_t;

typedef struct linked_list linked_list_t;

int is_list_empty(linked_list_t *list);

node_t *create_node(char *name);

node_t *destroy_node(node_t *node);

linked_list_t *create_linked_list();

linked_list_t *destroy_linked_list(linked_list_t *list);

node_t *find_node_by_name(linked_list_t *list, char *name);

node_t *insert_node(linked_list_t *list, node_t *node);

node_t *remove_node(linked_list_t *list, node_t *node);

node_t *move_node(linked_list_t *list, node_t *source, node_t *target);

void print_linked_list(linked_list_t *list);

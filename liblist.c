#include "liblist.h"

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

node_t *create_node(char *filename)
{
    node_t *node = malloc(sizeof(node_t));

    node->filename = filename;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

int insert_node(list_t *list, node_t *node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->size = 1;

        return 0;
    }

    node_t *tail = list->tail;

    tail->next = node;
    node->prev = tail;
    list->tail = node;
    list->size++;

    return 0;
}

int remove_node(list_t *list, node_t *node)
{
    if (list->head == NULL)
    {
        return 0;
    }
    if (list->head == node)
    {
        list->head = node->next;
        list->size--;

        return 0;
    }
    if (list->tail == node)
    {
        list->tail = node->prev;
        list->size--;

        return 0;
    }

    node_t *prev = node->prev;
    node_t *next = node->next;

    prev->next = next;
    next->prev = prev;
    list->size--;

    return 0;
}

node_t *find_node(list_t *list, char *filename)
{
    node_t *node = list->head;

    while (node != NULL)
    {
        if (node->filename == filename)
        {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

void print_list(list_t *list)
{
    node_t *node = list->head;

    if (node == NULL)
    {
        printf("- (empty)\n\n");
        return;
    }

    while (node != NULL)
    {
        printf("- %s\n", node->filename);
        node = node->next;
    }
}

int insert_file(list_t *list, char *filename, int counter, int size)
{
    if (access(filename, F_OK) == -1)
    {
        fprintf(stderr, "(%d/%d) ERROR: %s not found\n", counter, size - 1, filename);
        return 0;
    }

    node_t *node = create_node(filename);

    insert_node(list, node);
    printf("(%d/%d) inserted %s   \t", counter, size - 1, filename);
    printf("%d file(s) compressed\n", list->size);

    return 1;
}

int remove_file(list_t *list, char *filename, int counter, int size)
{
    if (access(filename, F_OK) == -1)
    {
        fprintf(stderr, "(%d/%d) ERROR: %s not found\n", counter, size - 1, filename);
        return 0;
    }

    node_t *node = find_node(list, filename);

    remove_node(list, node);
    printf("(%d/%d) removed %s   \t", counter, size - 1, filename);
    printf("%d file(s) compressed\n", list->size);

    return 1;
}

void write_file(list_t *list, char *filename)
{
    FILE *file = fopen(filename, "w");

    node_t *node = list->head;

    while (node != NULL)
    {
        fprintf(file, node->next ? "%s\n" : "%s", node->filename);
        node = node->next;
    }

    fclose(file);
}

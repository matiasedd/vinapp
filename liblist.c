#include "liblist.h"

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

list_t *free_list(list_t *list)
{
    node_t *node = list->head;

    while (node != NULL)
    {
        node_t *next = node->next;
        free(node->content);
        free(node);
        node = next;
    }

    free(list);

    return NULL;
}

node_t *create_node(char *filename)
{
    node_t *node = malloc(sizeof(node_t));

    node->next = NULL;
    node->prev = NULL;
    node->filename = filename;

    stat(filename, &node->st);
    node->content = malloc(node->st.st_size);

    FILE *fp = fopen(filename, "rb");
    fread(node->content, node->st.st_size, 1, fp);

    fclose(fp);

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
        if (strcmp(node->filename, filename) == 0)
            return node;
        
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

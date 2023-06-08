#include "liblist.h"

int is_list_empty(linked_list_t *list)
{
    return list->size == 0;
}

node_t *create_node(char *name)
{
    node_t *node = malloc(sizeof(node_t));

    node->next = NULL;
    node->name = name;
    stat(name, &node->stat);

    FILE *file = fopen(name, "rb");
    node->data = malloc(node->stat.st_size);
    fread(node->data, node->stat.st_size, 1, file);

    fclose(file);

    return node;
}

node_t *destroy_node(node_t *node)
{
    free(node->data);
    free(node);

    return NULL;
}

linked_list_t *create_linked_list()
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

linked_list_t *destroy_linked_list(linked_list_t *list)
{
    node_t *node = list->head;

    while (node != NULL)
    {
        node_t *next = node->next;
        destroy_node(node);
        node = next;
    }

    free(list);

    return NULL;
}

node_t *find_node_by_name(linked_list_t *list, char *name)
{
    node_t *node = list->head;

    while (node != NULL)
    {
        if (node->name == name)
            return node;

        node = node->next;
    }

    return NULL;
}

node_t *insert_node(linked_list_t *list, node_t *node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;

    return node;
}

node_t *remove_node(linked_list_t *list, node_t *node)
{
    if (node == list->head)
    {
        list->head = node->next;

        if (list->head == NULL)
            list->tail = NULL;
    }
    else
    {
        node_t *prev = list->head;

        while (prev->next != node)
            prev = prev->next;

        prev->next = node->next;

        if (prev->next == NULL)
            list->tail = prev;
    }

    list->size--;

    return destroy_node(node);
}

node_t *move_node(linked_list_t *list, node_t *source, node_t *target)
{
    if (source == target)
        return source;

    if (source == list->head)
    {
        list->head = source->next;

        if (list->head == NULL)
            list->tail = NULL;
    }
    else
    {
        node_t *prev = list->head;

        while (prev->next != source)
            prev = prev->next;

        prev->next = source->next;

        if (prev->next == NULL)
            list->tail = prev;
    }

    if (target == NULL)
    {
        source->next = NULL;
        list->tail = source;
    }
    else
    {
        source->next = target->next;
        target->next = source;
    }

    if (source->next == NULL)
        list->tail = source;

    if (source == list->tail)
        list->tail = target;

    if (target == list->tail)
        list->tail = source;

    if (source == list->head)
        list->head = target;

    if (target == list->head)
        list->head = source;

    return source;
}

void print_linked_list(linked_list_t *list)
{
    if (is_list_empty(list))
        printf("(empty)\n");

    node_t *node = list->head;

    while (node != NULL)
    {
        char *metadata = get_metadata(node->name, node->stat);
        printf("%s", metadata);
        free(metadata);
        node = node->next;
    }
}

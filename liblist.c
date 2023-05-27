#include "liblist.h"

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;

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

char *replace_spaces(char *str, char c)
{
    char *new_str = malloc(strlen(str) + 1);
    int i = 0;

    while (*str != '\0')
    {
        if (*str == ' ')
        {
            new_str[i] = c;
        }
        else
        {
            new_str[i] = *str;
        }

        str++;
        i++;
    }

    new_str[i] = '\0';

    return new_str;
}

node_t *create_node(char *filename)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return NULL;

    node->next = NULL;
    node->prev = NULL;
    node->filename = replace_spaces(filename, '_');

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

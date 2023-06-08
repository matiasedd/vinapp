#include "libvina.h"

int insert_member(char *name, linked_list_t *list)
{
    if (access(name, F_OK) == -1)
        return FAILURE;

    node_t *node = create_node(name);
    insert_node(list, node);

    return SUCCESS;
}

int move_member(char *source, char *target, linked_list_t *list)
{
    node_t *node_source = find_node_by_name(list, source);
    node_t *node_target = find_node_by_name(list, target);

    if (node_source == NULL || node_target == NULL)
        return FAILURE;

    move_node(list, node_source, node_target);

    return SUCCESS;
}

int remove_member(char *name, linked_list_t *list)
{
    if (is_list_empty(list))
        return FAILURE;

    node_t *node = find_node_by_name(list, name);

    if (node == NULL)
        return FAILURE;

    remove_node(list, node);

    return SUCCESS;
}

int refresh_backup(char *name, linked_list_t *list)
{
    FILE *file = fopen(name, "wb");

    if (file == NULL)
        return FAILURE;

    node_t *node = list->head;

    while (node != NULL)
    {
        fwrite(node->name, sizeof(char), strlen(node->name), file);
        fwrite("\n", sizeof(char), 1, file);
        node = node->next;
    }

    node = list->head;

    while (node != NULL)
    {
        fwrite(node->data, node->stat.st_size, 1, file);
        node = node->next;
    }

    fclose(file);

    return SUCCESS;
}

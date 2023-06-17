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

int load_backup(char *archiver, linked_list_t *list)
{
    FILE *file = fopen(archiver, "rb");

    if (file == NULL)
        return FAILURE;
    
    int length;
    struct stat stat;
    char *name = malloc(sizeof(char) * 256);

    while (1)
    {
        fread(&length, 1, sizeof(int), file);

        if (length == -1)
            break;

        fread(name, 1, length, file);
        fread(&stat, 1, sizeof(struct stat), file);

        node_t *node = malloc(sizeof(node_t));

        if (node == NULL)
            return FAILURE;

        node->next = NULL;
        node->stat = stat;
        node->name = malloc(sizeof(char) * length);

        if (node->name == NULL)
            return FAILURE;
            
        strncpy(node->name, name, length);
        insert_node(list, node);
    }

    free(name);
    fclose(file);

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
        int name_length = strlen(node->name);
        
        fwrite(&name_length, 1, sizeof(int), file);
        fwrite(node->name, 1, strlen(node->name), file);
        fwrite(&node->stat, 1, sizeof(struct stat), file);
        
        node = node->next;
    }

    int delimiter = -1;
    
    fwrite(&delimiter, 1, sizeof(int), file);
    fclose(file);

    return SUCCESS;
}

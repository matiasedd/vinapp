#include "libvina.h"

int insert_member(char *name, linked_list_t *list)
{
    if (access(name, F_OK) == -1)
    {
        printf("ERROR: %s does not exist\n", name);
        return FAILURE;
    }

    node_t *new_node = create_node(name);
    node_t *existing_node = find_node_by_name(list, name);

    if (existing_node == NULL)
    {
        insert_node(list, new_node);
        printf("INFO: inserted successfully\n");
    }
    else
    {
        replace_node(list, existing_node, new_node);
        printf("INFO: replaced successfully\n");
    }

    return SUCCESS;
}

int insert_recent(char *name, linked_list_t *list)
{
    if (access(name, F_OK) == -1)
    {
        printf("ERROR: %s does not exist\n", name);
        return FAILURE;
    }

    node_t *new_node = create_node(name);
    node_t *existing_node = find_node_by_name(list, name);

    if (is_recent(new_node, list))
    {
        if (existing_node == NULL)
        {
            insert_node(list, new_node);
            printf("INFO: inserted successfully\n");

            return SUCCESS;
        }
        else
        {
            replace_node(list, existing_node, new_node);
            printf("INFO: replaced successfully\n");

            return SUCCESS;
        }
    }

    printf("INFO: Member is not more recent, skipping insertion\n");
    destroy_node(new_node);

    return FAILURE;
}

int move_member(char *source, char *target, linked_list_t *list)
{
    node_t *node_source = find_node_by_name(list, source);
    node_t *node_target = find_node_by_name(list, target);

    if (node_source == NULL || node_target == NULL)
        return FAILURE;

    move_node(list, node_source, node_target);
    printf("INFO: %s moved to %s\n", source, target);

    return SUCCESS;
}

int extract_member(char *name, linked_list_t *list)
{
    if (is_list_empty(list))
    {
        printf("ERROR: archiver is empty\n");
        return FAILURE;
    }

    node_t *node = find_node_by_name(list, name);

    if (node == NULL)
    {
        printf("ERROR: %s is not in the archiver\n", name);
        return FAILURE;
    }

    extract_node(list, node);
    remove_node(list, node);
    printf("INFO: extracted successfully\n");

    return SUCCESS;
}

int extract_all(linked_list_t *list)
{
    if (is_list_empty(list))
    {
        printf("ERROR: archiver is already empty\n");
        return FAILURE;
    }

    node_t *node = list->head;

    while (node != NULL)
    {
        printf("INFO: extracting %s\n", node->name);
        extract_node(list, node);
        remove_node(list, node);
        node = node->next;
    }

    printf("INFO: extracted all members successfully\n");

    return SUCCESS;
}

int remove_member(char *name, linked_list_t *list)
{
    if (is_list_empty(list))
    {
        printf("ERROR: archiver is empty\n");
        return FAILURE;
    }

    node_t *node = find_node_by_name(list, name);

    if (node == NULL)
    {
        printf("ERROR: %s is not in the archiver\n", name);
        return FAILURE;
    }

    remove_node(list, node);
    printf("INFO: removed successfully\n");

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

    node_t *node = list->head;

    while (node != NULL)
    {
        node->data = malloc(node->stat.st_size);
        fread(node->data, node->stat.st_size, 1, file);
        node = node->next;
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
        int length = strlen(node->name);

        fwrite(&length, 1, sizeof(int), file);
        fwrite(node->name, 1, strlen(node->name), file);
        fwrite(&node->stat, 1, sizeof(struct stat), file);

        node = node->next;
    }

    int delimiter = -1;
    fwrite(&delimiter, 1, sizeof(int), file);
    node = list->head;

    while (node != NULL)
    {
        fwrite(node->data, 1, node->stat.st_size, file);
        node = node->next;
    }

    fclose(file);

    return SUCCESS;
}

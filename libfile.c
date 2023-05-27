#include "libfile.h"

int insert_file(list_t *list, char *filename)
{
    if (access(filename, F_OK) == -1)
        return 0;

    node_t *node = create_node(filename);

    if (node == NULL)
        return 0;

    insert_node(list, node);

    return 1;
}

int remove_file(list_t *list, char *filename)
{
    node_t *node = find_node(list, filename);

    if (node == NULL)
        return 0;

    remove_node(list, node);

    return 1;
}

int export_file(list_t *list, char *filename)
{
    node_t *node = find_node(list, filename);

    if (node == NULL)
        return 0;

    FILE *file = fopen(filename, "w");

    fwrite(node->content, node->st.st_size, 1, file);
    fclose(file);

    return 1;
}

void write_file(list_t *list, char *filename)
{
    FILE *file = fopen(filename, "w");

    char *header = "FILENAME\tSIZE\tMODE\tUID\tGID\tMTIME\t\t\tATIME\n";
    fwrite(header, strlen(header), 1, file);

    node_t *node = list->head;

    while (node != NULL)
    {
        char m_time[BUFFER_SIZE], a_time[BUFFER_SIZE];

        strftime(m_time, BUFFER_SIZE, "%Y-%m-%dT%H:%M:%S", localtime(&node->st.st_mtime));
        strftime(a_time, BUFFER_SIZE, "%Y-%m-%dT%H:%M:%S", localtime(&node->st.st_atime));
        
        asprintf(&header, "%s\t%ld\t%o\t%d\t%d\t%s\t%s\n", node->filename, node->st.st_size, node->st.st_mode, node->st.st_uid, node->st.st_gid, m_time, a_time);
        fwrite(header, strlen(header), 1, file);        
        
        free(header);
        node = node->next;
    }

    fwrite(DELIMITER, strlen(DELIMITER), 1, file);

    node = list->head;

    while (node != NULL)
    {
        fwrite(node->content, node->st.st_size, 1, file);
        fwrite("\n", 1, 1, file);
        node = node->next;
    }

    fclose(file);
}

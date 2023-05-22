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

int insert_file(list_t *list, char *filename, int counter, int size)
{
    if (access(filename, F_OK) == -1)
    {
        fprintf(stderr, "(%d/%d) ERROR: %s not found\n", counter, size - 1, filename);
        return 0;
    }

    node_t *node = create_node(filename);

    insert_node(list, node);
    printf("(%d/%d) inserted %s \t\t", counter, size - 1, filename);
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
    printf("(%d/%d) removed %s \t\t", counter, size - 1, filename);
    printf("%d file(s) compressed\n", list->size);

    return 1;
}

void write_file(list_t *list, char *filename)
{
    FILE *file = fopen(filename, "w");

    fwrite("filename size mode uid gid mtime atime\n", 39, 1, file);

    node_t *node = list->head;

    while (node != NULL)
    {
        char *header;
        char m_time[BUFFER_SIZE], a_time[BUFFER_SIZE];

        strftime(m_time, BUFFER_SIZE, "%Y-%m-%dT%H:%M:%S", localtime(&node->st.st_mtime));
        strftime(a_time, BUFFER_SIZE, "%Y-%m-%dT%H:%M:%S", localtime(&node->st.st_atime));
        
        asprintf(&header, "%s %ld %o %d %d %s %s\n", node->filename, node->st.st_size, node->st.st_mode, node->st.st_uid, node->st.st_gid, m_time, a_time);
        fwrite(header, strlen(header), 1, file);        
        
        free(header);
        node = node->next;
    }

    node = list->head;

    while (node != NULL)
    {
        fwrite(node->content, node->st.st_size, 1, file);
        fwrite("\n", 1, 1, file);
        node = node->next;
    }

    fclose(file);
}

int export_file(list_t *list, char *filename, int counter, int size)
{
    node_t *node = find_node(list, filename);

    if (node == NULL)
    {
        fprintf(stderr, "(%d/%d) ERROR: %s not found\n", counter, size - 1, filename);
        return 0;
    }

    FILE *file = fopen(filename, "w");

    fwrite(node->content, node->st.st_size, 1, file);

    fclose(file);

    printf("(%d/%d) exported %s\n", counter, size - 1, filename);

    return 1;
}
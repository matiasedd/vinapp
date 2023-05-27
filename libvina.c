#include "libvina.h"

void read_text(char *filename)
{
    FILE *fp = fopen(filename, "r");

    struct stat st;
    stat(filename, &st);
    char line[st.st_size];

    while (fgets(line, st.st_size, fp) != NULL)
        printf("%s", line);
    printf("\n");

    fclose(fp);
}

void handle_insert(int argc, char *argv[], list_t *list)
{
    for (int i = 3; i < argc; i++)
    {
        if (insert_file(list, argv[i]))
        {
            printf("(%d/%d) inserted %s \t\t\t", i - 2, argc - 3, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i - 2, argc - 3, argv[i]);
        }

        write_file(list, argv[2]);
    }

    printf("\n");
}

void handle_export(int argc, char *argv[], list_t *list)
{
    for (int i = 3; i < argc; i++)
    {
        if (export_file(list, argv[i]))
        {
            remove_file(list, argv[i]);
            printf("(%d/%d) exported %s   \t\t", i - 2, argc - 3, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i - 2, argc - 3, argv[i]);
        }
    }

    printf("\n");
}

void handle_remove(int argc, char *argv[], list_t *list)
{
    for (int i = 3; i < argc; i++)
    {
        if (remove_file(list, argv[i]))
        {
            printf("(%d/%d) removed %s   \t\t", i - 2, argc - 3, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i - 2, argc - 3, argv[i]);
        }

        write_file(list, argv[2]);
    }

    printf("\n");
}

void get_metadata(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[LINE_SIZE];
    printf("%s", "FILENAME\tSIZE\tMODE\tUID\tGID\tMTIME\t\t\tATIME\n");

    while (strcmp(fgets(line, LINE_SIZE, file), DELIMITER) != 0)
        printf("%s", line);
    printf("\n");   
}

#include "libvina.h"

void show_help()
{
    printf("Mostrar ajuda aqui...\n");
}

void show_header()
{
    FILE *fp = fopen("header.txt", "r");

    struct stat st;
    stat("header.txt", &st);
    char line[st.st_size];

    while (fgets(line, st.st_size, fp) != NULL)
        printf("%s", line);

    fclose(fp);
}

void handle_insert(int argc, char *argv[], list_t *list)
{
    for (int i = 3; i < argc; i++)
    {
        if (insert_file(list, argv[i]))
        {
            printf("(%d/%d) inserted %s   \t\t", i - 2, argc - 3, argv[i]);
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

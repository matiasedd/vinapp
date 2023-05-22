#include "liblist.h"

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

int main(int argc, char *argv[])
{
    show_header();

    list_t *list = create_list();

    for (int i = 1; i < argc; i++)
    {
        if (insert_file(list, argv[i]))
        {
            printf("(%d/%d) inserted %s   \t\t", i, argc - 1, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i, argc - 1, argv[i]);
        }

        write_file(list, "backup.vpp");
    }

    for (int i = 1; i < argc; i++)
    {
        if (export_file(list, argv[i]))
        {
            remove_file(list, argv[i]);
            printf("(%d/%d) exported %s   \t\t", i, argc - 1, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i, argc - 1, argv[i]);
        }
    }

    for (int i = 1; i < argc; i++)
    {
        if (remove_file(list, argv[i]))
        {
            printf("(%d/%d) removed %s   \t\t", i, argc - 1, argv[i]);
            printf("%d file(s) compressed\n", list->size);
        }
        else
        {
            fprintf(stderr, "(%d/%d) ERROR: %s not found\n", i, argc - 1, argv[i]);
        }

        write_file(list, "backup.vpp");
    }

    free_list(list);

    return 0;
}

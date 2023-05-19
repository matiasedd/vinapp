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
        if (insert_file(list, argv[i], i, argc))
            print_list(list);

        printf("\n");
        write_file(list, "backup.vpp");
    }

    /*
    for (int i = 1; i < argc; i++)
    {
        remove_file(list, argv[i], i, argc);
        print_list(list);
        write_file(list, "backup.vpp");
    }
    */

    free_list(list);

    return 0;
}

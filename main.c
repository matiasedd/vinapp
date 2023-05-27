#include "libvina.h"

int main(int argc, char *argv[])
{
    read_text("header.txt");

    list_t *list = create_list();

    int option;

    if (argc < 2)
    {
        printf("\t\t\tType -h for help\n\n\n\n");
        exit(EXIT_SUCCESS);
    }

    printf("\n\n");
    while ((option = getopt(argc, argv, "chirx")) != -1)
    {
        switch (option)
        {
            case 'c':
                get_metadata(argv[2]);
                break;
            case 'h':
                read_text("help.txt");
                exit(EXIT_SUCCESS);
            case 'i':
                handle_insert(argc, argv, list);
                break;
            case 'x':
                handle_export(argc, argv, list);
                break;
            case 'r':
                handle_remove(argc, argv, list);
                break;
        }
    }

    free_list(list);
    
    return EXIT_SUCCESS;
}

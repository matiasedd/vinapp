#include "libvina.h"

int main(int argc, char *argv[])
{
    show_header();

    list_t *list = create_list();

    int option;

    while ((option = getopt(argc, argv, "chirx")) != -1)
    {
        switch (option)
        {
            case 'c':
                get_metadata(argv[2]);
                break;
            case 'h':
                show_help();
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
            default:
                show_help();
                exit(EXIT_FAILURE);
        }
    }

    free_list(list);
    
    return EXIT_SUCCESS;
}

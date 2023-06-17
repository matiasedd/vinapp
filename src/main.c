#include "libvina.h"

int main(int argc, char *argv[])
{
    int opt;
    char *archiver = argv[2];
    linked_list_t *list = create_linked_list();

    load_backup(archiver, list);
    read_file("assets/banner.txt");

    while ((opt = getopt(argc, argv, "imxrch")) != -1)
    {
        switch (opt)
        {
        case 'i':
            for (int i = 3; i < argc; i++)
            {
                printf("[%d/%d] %-32s", i - 2, argc - 3, argv[i]);
                insert_member(argv[i], list);
            }
            refresh_backup(archiver, list);
            printf("\n");
            break;
        case 'm':
            char *source = argv[3];
            char *target = argv[4];
            
            move_member(source, target, list);
            refresh_backup(archiver, list);
            print_linked_list(list);
            
            break;
        case 'x':
            for (int i = 3; i < argc; i++)
            {
                printf("[%d/%d] %-24s", i - 2, argc - 3, argv[i]);
                extract_member(argv[i], list);
            }
            refresh_backup(archiver, list);
            printf("\n");
            break;
        case 'r':
            for (int i = 3; i < argc; i++)
            {
                printf("[%d/%d] %-24s", i - 2, argc - 3, argv[i]);
                remove_member(argv[i], list);
            }
            refresh_backup(archiver, list);
            printf("\n");
            break;
        case 'c':
            print_linked_list(list);
            break;
        case 'h':
            read_file("assets/help.txt");
            break;
        default:
            read_file("assets/help.txt");
            break;
        }
    }

    destroy_linked_list(list);

    return SUCCESS;
}

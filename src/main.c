#include "libvina.h"

int main(int argc, char *argv[])
{
    linked_list_t *list = create_linked_list();

    load_backup(argv[2], list);
    read_file("assets/banner.txt");

    int opt;

    while ((opt = getopt(argc, argv, "irch")) != -1)
    {
        switch (opt)
        {
        case 'i':
            for (int i = 3; i < argc; i++)
            {
                printf("[%d/%d] %-24s", i - 2, argc - 3, argv[i]);
                
                if (insert_member(argv[i], list) == SUCCESS)
                    printf("INSERTED\n");
                else
                    printf("ERROR: file not found\n");    
            }
            
            refresh_backup(argv[2], list);
            break;
        case 'r':
            for (int i = 3; i < argc; i++)
            {
                printf("[%d/%d] %-24s", i - 2, argc - 3, argv[i]);
                
                if (remove_member(argv[i], list) == SUCCESS)
                    printf("REMOVED\n");
                else
                    printf("ERROR: something went wrong\n");    
            }
            
            refresh_backup(argv[2], list);
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

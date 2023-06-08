#include "libvina.h"

int main(int argc, char *argv[])
{
    read_file("assets/banner.txt");

    linked_list_t *list = create_linked_list();

    int opt;

    while ((opt = getopt(argc, argv, "ihr")) != -1)
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
            break;
        case 'h':
            read_file("assets/help.txt");
            break;
        default:
            read_file("assets/help.txt");
            break;
        }
    }

    printf("\n");
    print_linked_list(list);
    destroy_linked_list(list);

    return SUCCESS;
}

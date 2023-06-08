#include "libvina.h"

int main(int argc, char *argv[])
{
    read_file("assets/banner.txt");

    linked_list_t *list = create_linked_list();

    int opt;

    while ((opt = getopt(argc, argv, "ih")) != -1)
    {
        switch (opt)
        {
        case 'i':
            for (int i = 2; i < argc; i++)
            {
                printf("[%d/%d] %-32s", i - 1, argc - 2, argv[i]);
                
                if (insert_member(argv[i], list) == SUCCESS)
                    printf("DONE\n");
                else
                    printf("ERROR: file not found\n");
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

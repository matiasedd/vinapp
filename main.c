#include "liblist.h"

int main(int argc, char *argv[])
{
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

    return 0;
}

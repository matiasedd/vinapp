#include "liblist.h"

int main(int argc, char *argv[])
{
    list_t *list = create_list();

    for (int i = 1; i < argc; i++)
    {
        insert_file(list, argv[i], i, argc);
        print_list(list);
    }

    for (int i = 1; i < argc; i++)
    {
        remove_file(list, argv[i], i, argc);
        print_list(list);
    }

    return 0;
}

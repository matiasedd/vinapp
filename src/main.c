#include "libvina.h"

int main(int argc, char *argv[])
{
    linked_list_t *list = create_linked_list();

    for (int i = 1; i < argc; i++)
        insert_member(argv[i], list);

    destroy_linked_list(list);

    return SUCCESS;
}

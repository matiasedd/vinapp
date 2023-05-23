#include "libvina.h"

int main(int argc, char *argv[])
{
    // show_header();

    list_t *list = create_list();

    handle_insert(argc, argv, list);
    handle_export(argc, argv, list);
    handle_remove(argc, argv, list);

    free_list(list);

    return 0;
}

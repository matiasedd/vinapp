#include "libvina.h"

int main(int argc, char *argv[])
{
    int opt;

    linked_list_t *list = create_linked_list();

    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
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

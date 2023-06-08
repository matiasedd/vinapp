#include "libvina.h"

int main(int argc, char *argv[])
{
    read_file("assets/banner.txt");
    
    linked_list_t *list = create_linked_list();

    int opt;

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

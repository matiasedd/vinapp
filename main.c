#include "libvina.h"

int main()
{
    linked_list_t *list = create_linked_list();

    insert_member("arq.txt", list);
    insert_member("foto.jpg", list);
    insert_member("despesas.ods", list);

    move_member("arq.txt", "despesas.ods", list);

    remove_member("foto.jpg", list);
    remove_member("arq.txt", list);
    remove_member("despesas.ods", list);

    destroy_linked_list(list);

    return 0;
}

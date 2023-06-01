#include "liblist.h"

int main() {
    linked_list_t *list = create_linked_list();
    
    node_t *node1 = create_node("arq.txt");
    insert_node(list, node1);
    node_t *node2 = create_node("foto.jpg");
    insert_node(list, node2);
    node_t *node3 = create_node("despesas.ods");
    insert_node(list, node3);
    
    print_linked_list(list);
    move_node(list, node1, node3);
    print_linked_list(list);

    destroy_linked_list(list);
    
    return 0;
}
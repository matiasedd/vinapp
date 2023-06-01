#include "liblist.h"

int main() {
    linked_list_t *list = create_linked_list();
    
    node_t *node1 = create_node(1);
    insert_node(list, node1);
    node_t *node2 = create_node(2);
    insert_node(list, node2);
    node_t *node3 = create_node(3);
    insert_node(list, node3);
    node_t *node4 = create_node(4);
    insert_node(list, node4);
    node_t *node5 = create_node(5);
    insert_node(list, node5);

    move_node(list, node2, node5);
    
    print_linked_list(list);
    destroy_linked_list(list);
    
    return 0;
}
#include "libutils.h"

/**
 * @struct node
 * Represents a node in a linked list.
 */
struct node {
    char *name;
    void *data;
    struct stat stat;
    struct node *next;
};

/**
 * @struct linked_list
 * Represents a linked list.
 */
struct linked_list {
    int size;
    struct node *head;
    struct node *tail;
};

typedef struct node node_t;
typedef struct linked_list linked_list_t;

/**
 * @brief Check if the linked list is empty.
 * @param list A pointer to the linked list to be checked.
 * @return 1 if the linked list is empty, 0 otherwise.
 */
int is_list_empty(linked_list_t *list);

/**
 * @brief Create a new node with the given name.
 * @param name A pointer to a string representing the name of the node.
 * @return A pointer to the newly created node.
 */
node_t *create_node(char *name);

/**
 * @brief Destroy a node and free its allocated memory.
 * @param node A pointer to the node to be destroyed.
 * @return NULL.
 */
node_t *destroy_node(node_t *node);

/**
 * @brief Create a new linked list.
 * @return A pointer to the newly created linked list.
 */
linked_list_t *create_linked_list();

/**
 * @brief Destroy a linked list and free its allocated memory.
 * @param list A pointer to the linked list to be destroyed.
 * @return NULL.
 */
linked_list_t *destroy_linked_list(linked_list_t *list);

/**
 * @brief Find a node in the linked list by its name.
 * @param list A pointer to the linked list to search in.
 * @param name A pointer to a string representing the name of the node to find.
 * @return A pointer to the found node if it exists, NULL otherwise.
 */
node_t *find_node_by_name(linked_list_t *list, char *name);

/**
 * @brief Insert a node into the linked list.
 * @param list A pointer to the linked list to insert into.
 * @param node A pointer to the node to be inserted.
 * @return A pointer to the inserted node.
 */
node_t *insert_node(linked_list_t *list, node_t *node);

/**
 * @brief Remove a node from the linked list.
 * @param list A pointer to the linked list to remove from.
 * @param node A pointer to the node to be removed.
 * @return A pointer to the removed node.
 */
node_t *remove_node(linked_list_t *list, node_t *node);

/**
 * @brief Move a node from one position to another in the linked list.
 * @param list A pointer to the linked list.
 * @param source A pointer to the node to be moved.
 * @param target A pointer to the node after which the source node should be placed.
 * @return A pointer to the moved node.
 */
node_t *move_node(linked_list_t *list, node_t *source, node_t *target);

/**
 * @brief Print the contents of the linked list.
 * @param list A pointer to the linked list to be printed.
 */
void print_linked_list(linked_list_t *list);

#include "liblist.h"

/**
 * @brief Insert a member into the linked list.
 * @param name The name of the member to be inserted.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the member was inserted successfully, FAILURE otherwise.
 */
int insert_member(char *name, linked_list_t *list);

/**
 * @brief Move a member from one position to another in the linked list.
 * @param source The name of the member to be moved.
 * @param target The name of the member after which the source member should be placed.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the member was moved successfully, FAILURE otherwise.
 */
int move_member(char *source, char *target, linked_list_t *list);

/**
 * @brief Extract a member from the linked list.
 * @param name The name of the member to be extracted.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the member was extracted successfully, FAILURE otherwise.
 */
int extract_member(char *name, linked_list_t *list);

/**
 * @brief Extract all members from the linked list.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the members were extracted successfully, FAILURE otherwise.
 */
int extract_all(linked_list_t *list);

/**
 * @brief Remove a member from the linked list.
 * @param name The name of the member to be removed.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the member was removed successfully, FAILURE otherwise.
 */
int remove_member(char *name, linked_list_t *list);

/**
 * @brief Load a backup of the linked list from a file.
 * @param name The name of the backup file.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the backup was loaded successfully, FAILURE otherwise.
 */
int load_backup(char *name, linked_list_t *list);

/**
 * @brief Refresh the backup file with the current state of the linked list.
 * @param name The name of the backup file.
 * @param list A pointer to the linked list.
 * @return SUCCESS if the backup was refreshed successfully, FAILURE otherwise.
 */
int refresh_backup(char *name, linked_list_t *list);

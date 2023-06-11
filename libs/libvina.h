#include "liblist.h"

#define DIR_DELIMITER "&"

int insert_member(char *name, linked_list_t *list);

int move_member(char *source, char *target, linked_list_t *list);

int remove_member(char *name, linked_list_t *list);

int load_backup(char *name, linked_list_t *list);

int refresh_backup(char *name, linked_list_t *list);

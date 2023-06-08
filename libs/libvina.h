#include <getopt.h>

#include "liblist.h"

#define SUCCESS 0
#define FAILURE 1

int insert_member(char *name, linked_list_t *list);

int move_member(char *source, char *target, linked_list_t *list);

int remove_member(char *name, linked_list_t *list);

void read_file(char *filename);

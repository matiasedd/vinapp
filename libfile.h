#include "liblist.h"

#define DELIMITER "CONTENT\n"

int insert_file(list_t *list, char *filename);

int remove_file(list_t *list, char *filename);

int export_file(list_t *list, char *filename);

void write_file(list_t *list, char *filename);

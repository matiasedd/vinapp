#include "libfile.h"

#define LINE_SIZE 16
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void read_text(char *filename);

void handle_insert(int argc, char *argv[], list_t *list);

void handle_export(int argc, char *argv[], list_t *list);

void handle_remove(int argc, char *argv[], list_t *list);

void get_metadata(char *filename);

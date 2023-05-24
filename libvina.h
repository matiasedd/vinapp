#include "libfile.h"

#define START 3
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void show_help();

void show_header();

void handle_insert(int argc, char *argv[], list_t *list);

void handle_export(int argc, char *argv[], list_t *list);

void handle_remove(int argc, char *argv[], list_t *list);

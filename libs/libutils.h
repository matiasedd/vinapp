#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>

#define SUCCESS 0
#define FAILURE 1

#define SPACE_REPLACEMENT '_'

void read_file(char *name);

char *replace(char *string, char old, char replacement);

char *get_metadata(char *name, struct stat st);

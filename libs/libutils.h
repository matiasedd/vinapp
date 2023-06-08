#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

#define BUFFER_SIZE 20

void print_permissions(struct stat st);

void print_owner(struct stat st);

void print_time(struct stat st);

void print_size(struct stat st);

void print_name(char *name);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <getopt.h>
#include <sys/stat.h>

#define SUCCESS 0
#define FAILURE 1

void print_permissions(struct stat st);

void print_owner(struct stat st);

void print_time(struct stat st);

void print_size(struct stat st);

void print_name(char *name);

void read_file(char *filename);

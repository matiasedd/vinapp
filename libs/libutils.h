#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <libgen.h>

#define SUCCESS 0
#define FAILURE 1

#define SPACE_REPLACEMENT '_'

/**
 * @brief Read the contents of a file and print them to the standard output.
 * @param name The name of the file to be read.
 */
void read_file(char *name);

/**
 * @brief Replace all occurrences of a character in a string with a replacement character.
 * @param string The input string.
 * @param old The character to be replaced.
 * @param replacement The replacement character.
 * @return A pointer to the modified string.
 */
char *replace(char *string, char old, char replacement);

/**
 * @brief Get metadata information for a file.
 * @param name The name of the file.
 * @param st A struct stat object containing the file's metadata.
 * @return A string representation of the file's metadata.
 */
char *get_metadata(char *name, struct stat st);

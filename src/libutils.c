#include "libutils.h"

void read_file(char *name, int required)
{
    FILE *file = fopen(name, "r");

    if (file == NULL)
    {
        if (required)
        {
            fprintf(stderr, "ERROR: Could not open file %s\n", name);
            exit(FAILURE);
        }
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
        printf("%s", line);

    fclose(file);
}

char *replace(char *string, char old, char replacement)
{
    char *result = malloc(sizeof(char) * strlen(string));

    if (result == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate memory for result\n");
        exit(FAILURE);
    }

    for (int i = 0; i < strlen(string); i++)
        result[i] = string[i] == old ? replacement : string[i];

    return result;
}

char* get_metadata(char* name, struct stat st)
{
    char* metadata = malloc(sizeof(char) * 100);

    sprintf(metadata, "%s%s%s%s%s%s%s%s%s%s",
        (st.st_mode & S_IFDIR) ? "d" : "-",
        (st.st_mode & S_IRUSR) ? "r" : "-",
        (st.st_mode & S_IWUSR) ? "w" : "-",
        (st.st_mode & S_IXUSR) ? "x" : "-",
        (st.st_mode & S_IRGRP) ? "r" : "-",
        (st.st_mode & S_IWGRP) ? "w" : "-",
        (st.st_mode & S_IXGRP) ? "x" : "-",
        (st.st_mode & S_IROTH) ? "r" : "-",
        (st.st_mode & S_IWOTH) ? "w" : "-",
        (st.st_mode & S_IXOTH) ? "x" : "-");

    struct passwd* pwd = getpwuid(st.st_uid);
    struct group* grp = getgrgid(st.st_gid);
    sprintf(metadata + 10, " %s/%s", pwd->pw_name, grp->gr_name);

    char formatted_time[20];
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M", localtime(&st.st_mtime));

    sprintf(metadata + strlen(metadata), " %8ld", st.st_size);
    sprintf(metadata + strlen(metadata), " %s", formatted_time);
    sprintf(metadata + strlen(metadata), " %s\n", name);

    return metadata;
}

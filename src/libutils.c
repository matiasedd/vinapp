#include "libutils.h"

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

void read_file(char *name)
{
    FILE *file = fopen(name, "r");

    if (file == NULL)
    {
        fprintf(stderr, "ERROR: %s not found\n", name);
        exit(FAILURE);
    }

    char c;

    printf("\n");
    while ((c = fgetc(file)) != EOF)
        printf("%c", c);
    printf("\n");

    fclose(file);
}

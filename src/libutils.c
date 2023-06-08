#include "libutils.h"

void print_permissions(struct stat st)
{
    printf("%s", st.st_mode & S_IFDIR ? "d" : "-");
    printf("%s", st.st_mode & S_IRUSR ? "r" : "-");
    printf("%s", st.st_mode & S_IWUSR ? "w" : "-");
    printf("%s", st.st_mode & S_IXUSR ? "x" : "-");
    printf("%s", st.st_mode & S_IRGRP ? "r" : "-");
    printf("%s", st.st_mode & S_IWGRP ? "w" : "-");
    printf("%s", st.st_mode & S_IXGRP ? "x" : "-");
    printf("%s", st.st_mode & S_IROTH ? "r" : "-");
    printf("%s", st.st_mode & S_IWOTH ? "w" : "-");
    printf("%s", st.st_mode & S_IXOTH ? "x" : "-");
}

void print_owner(struct stat st)
{
    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grp = getgrgid(st.st_gid);
    printf(" %s/%s", pwd->pw_name, grp->gr_name);
}

void print_time(struct stat st)
{
    char formatted_time[BUFFER_SIZE];
    strftime(formatted_time, BUFFER_SIZE, "%Y-%m-%d %H:%M", localtime(&st.st_mtime));
    printf(" %s", formatted_time);
}

void print_size(struct stat st)
{
    printf("\t%ld", st.st_size);
}

void print_name(char *name)
{
    printf(" %s\n", name);
}

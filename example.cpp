#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char buf[100];
    struct stat s;
    int fd1, fd2, n;

    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening source file");
        return 1;
    }

    fd2 = creat(argv[2], 0777);
    if (fd2 == -1)
    {
        perror("Error creating destination file");
        close(fd1);
        return 1;
    }

    while ((n = read(fd1, buf, sizeof(buf))) > 0)
    {
        if (write(fd2, buf, n) != n)
        {
            perror("Error writing to destination file");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    close(fd1);
    close(fd2);

    if (stat(argv[2], &s) == -1)
    {
        perror("Error getting file information");
        return 1;
    }

    printf("\tUID FOR FILE.......> %d\n", s.st_uid);
    printf("\tFILE ACCESS TIME.....> %s", ctime(&s.st_atime));
    printf("\tFILE MODIFIED TIME........> %s", ctime(&s.st_mtime));
    printf("\tFILE I-NODE NUMBER...... > %ld\n", (long)s.st_ino);
    printf("\tPERMISSION FOR FILE.....> %o\n", s.st_mode & 0777);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    line = get_next_line(-1);
    free(line);
    line = get_next_line(100);
    free(line);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening the file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
	break;
    }

    close(fd);

    return 0;
}


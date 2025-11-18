#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    int line_count;

    // Open file
    fd = open("bible.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }

    // Read all lines
    line_count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count, line);
        free(line);
        line_count++;
    }

    printf("Total lines read: %d\n", line_count - 1);

    close(fd);
    return (0);
}


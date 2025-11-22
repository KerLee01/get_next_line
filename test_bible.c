#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int line_count = 0;
    int char_count = 0;

    printf("=== Testing get_next_line with Bible ===\n\n");

    fd = open("bible.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("❌ Error: Could not open bible.txt\n");
        printf("Make sure bible.txt is in the current directory!\n");
        return (1);
    }

    printf("Reading file...\n");

    // Read all lines
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        
        // Count characters
        int i = 0;
        while (line[i])
        {
            char_count++;
            i++;
        }
        
        // Print progress every 1000 lines
        if (line_count % 1000 == 0)
            printf("Read %d lines...\n", line_count);
        
        free(line);
    }

    close(fd);

    printf("\n✅ Success!\n");
    printf("Total lines read: %d\n", line_count);
    printf("Total characters: %d\n", char_count);
    printf("Average line length: %.2f characters\n", 
           (float)char_count / line_count);

    return (0);
}

#include "get_next_line.h"
#include <strings.h>

int main (void)
{
	int fd;
	int i = 0;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while(i != 3)
	{
		if(line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	if(line == NULL)
		printf("yes\n");

	return (0);
}

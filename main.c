#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	
	line = get_next_line(fd);
	while(line != NULL)
	{
		if(line)
			write(1, line, ft_strlen(line));
		line = get_next_line(fd);
	}

	return (0);
}

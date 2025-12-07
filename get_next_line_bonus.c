#include "get_next_line.h"
#include <string.h>

char *read_more(char *saved, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	int bytes_total;
	int i;
	int saved_size;
	
	bytes_total = 0;
	i = 0;
	if (!saved)
		saved = ft_strdup("");
	if (!saved)
		return (NULL);
	saved_size = ft_strlen(saved);
	while (!ft_strchr(saved + bytes_total, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(saved);
			return (NULL);
		}
		if(bytes == 0)
		{
			if(saved[0] != '\0')
				return (saved);
			if(saved)
				free(saved);
			return (NULL);
		}
		buf[bytes] = '\0';
		saved = ft_strjoin(saved, buf, saved_size, bytes);
		if (saved == NULL)
			return NULL;
		if(i++ != 0)
			bytes_total += bytes;
		saved_size += bytes;
	}
	return (saved);
}

char *get_print_line(char *read_line)
{
	char *line;
	int i;

	i = 0;
	if (read_line == NULL)
		return NULL;

	while(read_line[i] && read_line[i] != '\n')
		i++;

	if(read_line[i] == '\n')
		i++;

	line = malloc(sizeof(char) * (i + 1));
	if(!line)
		return NULL;

	ft_memcpy(line, read_line, i-1);
	// i = 0;
	// while(read_line[i] && read_line[i] != '\n')
	// {
	// 	line[i] = read_line[i];
	// 	i++;
	// }
	//
	// if(read_line[i] == '\n')
	// {
	// 	line[i] = '\n';
	// 	i++;
	// }

	line[i] = '\0';

	return line;
}

char *update_buffer(char *to_update)
{
    char *new_buffer;
    int i;
    int j;

    if (!to_update)
        return (NULL);

    i = 0;
    while (to_update[i] && to_update[i] != '\n')
        i++;
    
    if (!to_update[i])
    {
        free(to_update);
        return (NULL);
    }
    
    i++;
    
    if (!to_update[i])
    {
        free(to_update);
        return (NULL);
    }
    
    new_buffer = malloc(strlen(to_update) - i + 1);
    if (!new_buffer)
    {
        free(to_update);
        return (NULL);
    }
    
    j = 0;
    while (to_update[i])
    {
        new_buffer[j] = to_update[i];
        j++;
        i++;
    }
    new_buffer[j] = '\0';
    
    free(to_update);
    
    return (new_buffer);
}

char *get_next_line(int fd)
{
	static char *buffer[MAX_FD];
	char *line;
	
	buffer[fd] = read_more(buffer[fd], fd);

	if(!buffer[fd])
		return NULL;
	line = get_print_line(buffer[fd]);
	if(line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	buffer[fd] = update_buffer(buffer[fd]);
	return line;
}

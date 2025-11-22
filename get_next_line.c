#include "get_next_line.h"

char *read_more(char *saved, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	
	// Since saved(aka buffer[fd] is all initialised to NULL, 
	// we will have to make it an actual string to concatenate another string to it.
	if (!saved)
		saved = ft_strdup("");

	// As ft_strdup returns NULL when an error occurs, 
	// we have to check it.
	if (!saved)
		return (NULL);

	// Loop until '\n' is found or when bytes is less than or equal to 0.
	while (!strchr(saved, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		// If read returns -1 (error occured
		// We have to free what is saved in saved (aka buffer[fd])
		// and return NULL
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
		saved = ft_strjoin(saved, buf);
	}
	return (saved);
}

char *get_line(char *read_line)
{
	char *line;
	int i;

	i = 0;
	// Check if end of line is reached or no strings found
	if (read_line == NULL)
		return NULL;

	// find the length of string uptil '\n'
	while(read_line[i] && read_line[i] != '\n')
		i++;

	// add 1 to i if the next character is '\n'
	if(read_line[i] == '\n')
		i++;

	line = malloc(sizeof(char) * (i + 1));
	if(!line)
		return NULL;

	i = 0;
	while(read_line[i] && read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}

	if(read_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}

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
    
    // Find the first newline in the line
    // if no newline is found, the EOF is reached
    i = 0;
    while (to_update[i] && to_update[i] != '\n')
        i++;
    
    // No newline found = reached EOF
    // free(to_update) as we have reached EOF
    if (!to_update[i])
    {
        free(to_update);
        return (NULL);
    }
    
    // Skip past the newline
    i++;
    
    // Nothing after newline
    if (!to_update[i])
    {
        free(to_update);
        return (NULL);
    }
    
    // Allocate new buffer for remainder
    new_buffer = malloc(strlen(to_update) - i + 1);
    if (!new_buffer)
    {
        free(to_update);
        return (NULL);
    }
    
    // Copy remainder
    j = 0;
    while (to_update[i])
    {
        new_buffer[j] = to_update[i];
        j++;
        i++;
    }
    new_buffer[j] = '\0';
    
    // Free old buffer
    free(to_update);
    
    return (new_buffer);
}

char *get_next_line(int fd)
{
	// Used to store any leftover data past '\n'
	// All initalised to NULL at first
	static char *buffer[MAX_FD];

	// line to return
	char *line;
	
	// read_more function is used to read the file based on the file descriptor
	// with the buffer size based on BUFFER_SIZE determined during runtime or by default, 42.
	// read_more returns the line when '\n' is found.
	// if \n is not found, read_more will read until EOF and return NULL;
	buffer[fd] = read_more(buffer[fd], fd);

	if(!buffer[fd])
		return NULL;
	line = get_line(buffer[fd]);
	
	buffer[fd] = update_buffer(buffer[fd]);

	return line;
}

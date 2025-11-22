/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:24:19 by kerlee            #+#    #+#             */
/*   Updated: 2025/11/20 17:31:42 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_more(char *saved, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;

	if (!saved)
		saved = ft_strdup("");
	if (!saved)
		return (NULL);
	while (!strchr(saved, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0 && saved[0] != '\0')
			return (saved);
		if (bytes == -1 || (bytes == 0 && saved[0] == '\0'))
		{
			if (saved)
				free(saved);
			return (NULL);
		}
		buf[bytes] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	return (saved);
}

char	*get_toprint_line(char *read_line)
{
	char	*line;
	int		i;

	i = 0;
	if (read_line == NULL)
		return (NULL);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (read_line[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	if (read_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *to_update)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!to_update)
		return (NULL);
	i = 0;
	while (to_update[i] && to_update[i] != '\n')
		i++;
	if (!to_update[i] || !to_update[i + 1])
		return (free(to_update), NULL);
	new_buffer = malloc(strlen(to_update) - i + 1);
	if (!new_buffer)
		return (free(to_update), NULL);
	j = 0;
	while (to_update[i])
		new_buffer[j++] = to_update[i++];
	new_buffer[j] = '\0';
	return (free(to_update), new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	buffer[fd] = read_more(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = get_toprint_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

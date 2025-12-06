#include "get_next_line.h"

char *join_line(t_list *node)
{
	int i;
	char *joined_str;
	char *current_str;

	i = 0;
	joined_str = malloc(sizeof(*joined_str) * (count_join_length(node) + 1));
	if(joined_str == NULL)
		return NULL;
	while(node != NULL)
	{
		current_str = node->content;
		while(*current_str != '\0' && *current_str != '\n')
		{
			joined_str[i] = *current_str;
			current_str++;
			i++;
		}
		node = node->next;
		if(*current_str == '\n')
			joined_str[i++] = '\n';
	}
	joined_str[i] = '\0';
	if(joined_str[0] == '\0')
		return (free(joined_str), NULL);
	return joined_str;
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*str;

	str = (char *)s;
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc % 256)
			return (str);
		str++;
	}
	if (*str == '\0' && uc == '\0')
		return (str);
	return (NULL);
}

t_list *read_more(int fd, t_list *node)
{
	int byte;
	char *buffer;
	t_list *new;
	t_list* start;

	if(node == NULL)
		return NULL;
	start = node;
	while(ft_strchr(node->content, '\n') == NULL)
	{
		buffer = malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
		if(buffer == NULL)
			return NULL;
		byte = read(fd, buffer, BUFFER_SIZE);
		if(byte == -1)
		{
			free(buffer);
			free_nodes(start);
			return NULL;
		}
		if(byte == 0)
		{
			free(buffer);
			return start;
		}
		buffer[byte] = '\0';
		new = create_new_node(buffer);
		add_node(node, new);
		node = new;
	}
	return start;
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char *updated_content(char *old_content)
{
	int i;
	int j;
	char *updated;

	i = 0;
	j = 0;
	while(old_content[j] != '\n')
		j++;
	if(old_content[j] == '\n')
		j++;
	updated = malloc(sizeof(*updated_content) * (ft_strlen(old_content) - j + 1));
	while(old_content[j] != '\0')
	{
		updated[i] = old_content[j];
		j++;
		i++;
	}
	updated[i] = '\0';
	return updated;
}

t_list *update_library(t_list *list)
{
	t_list *buffer;
	char *str;
	char *updated;

	while(list->next != NULL)
	{
		buffer = list;
		free(list->content);
		list = list->next;
		free(buffer);
	}
	str = list->content;
	if(strchr(str, '\n') != NULL)
	{
		updated = updated_content(str);
		free(list->content);
		list->content = updated;
		return list;
	}
	free(list->content);
	free(list);
	return NULL;
}

char *get_next_line(int fd)
{
	static t_list *library_fd[4096];
	char *line;

	if(library_fd[fd] == NULL)
		library_fd[fd] = create_new_node(strdup(""));

	if(library_fd[fd] == NULL)
		return NULL;

	library_fd[fd] = read_more(fd, library_fd[fd]);
	
	if(library_fd[fd] == NULL)
		return NULL;

	line = join_line(library_fd[fd]);
	library_fd[fd] = update_library(library_fd[fd]);

	return line;
}

#include "get_next_line.h"

void add_node(t_list *current, t_list* new)
{
	current->next = new;
}

int count_join_length(t_list *node)
{
	int j;
	int length;
	char *current_str;

	length = 0;
	while(node->next != NULL)
 	{
		if((node->content)[0] != '\0')
			length += BUFFER_SIZE;
		node = node->next;
	}
	j = 0;
	current_str = node->content;
	while(current_str[j] != '\0' && current_str[j] != '\n')
	{
		length++;
		j++;
	}
	if(current_str[j] == '\n')
		length++;
	return length;
}

t_list *create_new_node(char *content)
{
	t_list *new = malloc(sizeof(*new));

	new->content = content;
	new->next = NULL;

	return new;
}

void free_nodes(t_list *current)
{
	t_list *buffer;

	while(current->next != NULL)
	{
		free(current->content);
		buffer = current;
		current = current->next;
		free(buffer);
	}
	free(current->content);
	free(current);
}

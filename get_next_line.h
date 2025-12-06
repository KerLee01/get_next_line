#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
   char *content;
   struct s_list *next;
} t_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

t_list *create_new_node(char *content);
char *ft_strjoin(const char *s1, const char *s2);
char *get_next_line(int fd);
void free_nodes(t_list *current);
void add_node(t_list *current, t_list *new);
int count_join_length(t_list *node);
#endif

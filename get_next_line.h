#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef MAX_FD  
# define MAX_FD 1024
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2, int s1_length, int s2_length);
char *ft_strdup(const char *s);

#endif

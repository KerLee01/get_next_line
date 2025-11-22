#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);

#endif

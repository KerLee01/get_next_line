#include "get_next_line.h"
#include <string.h>

size_t  ft_strlen(const char *s)
{
        size_t  count;

        count = 0;
        while (*s)
        {
                count++;
                s++;
        }
        return (count);
}

char    *ft_strchr(const char *s, int c)
{
        unsigned char   uc;
        char                    *str;

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

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        unsigned long            *d;
        const unsigned long      *s;
	unsigned char *d_byte;
	const unsigned char *s_byte;

        if (dest == NULL && src == NULL)
                return (NULL);
        d = (unsigned long *)dest;
        s = (const unsigned long*)src;
        if (n == 0)
                return (dest);
        while (n >= sizeof(unsigned long))
        {
                *d = *s;
		d++;
                s++;
                n -= sizeof(unsigned long);
        }

	d_byte = (unsigned char *)d;
	s_byte = (const unsigned char *)s;
	while(n > 0)
	{
		*d_byte = *s_byte;
		d_byte++;
		s_byte++;
		n--;
	}
        return (dest);
}

char *ft_strjoin(char const *s1, char const *s2, int s1_length, int s2_length)
{
  char *result;

  result = malloc(sizeof(*s1) * (s1_length + s2_length + 1));
  if(!result)
  {
	  free((char*)s1);
    return NULL;
  }
  ft_memcpy(result, s1, s1_length);
  while(*s2)
  {
    result[s1_length] = *s2;
    s1_length++;
    s2++;
  }
  result[s1_length] = '\0';

  if(s1)
	  free((void *)s1);
  return result;
}

char *ft_strdup(const char *s)
{
  int s_length;
  char *dup;
  int i;

  i = 0;
  if(!s)
    return NULL;

  s_length = ft_strlen(s);
  dup = malloc(sizeof(*s) * (s_length + 1));
  if(!dup)
    return NULL;
  while(*s)
  {
    dup[i] = *s;
    i++;
    s++;
  }
  dup[i] = '\0';
  return dup;
}

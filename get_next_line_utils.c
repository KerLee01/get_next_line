#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  int s1_length;
  int s2_length;
  char *result;

  s1_length = strlen(s1);
  s2_length = strlen(s2);
  result = malloc(sizeof(*s1) * (s1_length + s2_length + 1));
  if(!result)
    return NULL;
  memcpy(result, s1, s1_length);
  while(*s2)
  {
    result[s1_length] = *s2;
    s1_length++;
    s2++;
  }
  result[s1_length] = '\0';
  return result;
}

#include <stdlib.h>

char *ft_strdup(const char *s)
{
  int s_length;
  char *dup;

  if(!s)
    return NULL;

  s_length = strlen(s);

  dup = malloc(sizeof(*s) * (s_length + 1));
  if(!dup)
    return NULL;
  while(*s)
  {
    *dup = *s;
    dup++;
    s++;
  }
  *dup = '\0';
  return dup - s_length;
}

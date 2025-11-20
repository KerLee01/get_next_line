/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:27:11 by kerlee            #+#    #+#             */
/*   Updated: 2025/11/20 17:14:26 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	int			i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	destination = (char *)dest;
	source = (const char *)src;
	if (n == 0)
		return (dest);
	while (n != 0)
	{
		destination[i] = *source;
		i++;
		source++;
		n--;
	}
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_length;
	int		s2_length;
	char	*result;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = malloc(sizeof(*s1) * (s1_length + s2_length + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_length);
	while (*s2)
	{
		result[s1_length] = *s2;
		s1_length++;
		s2++;
	}
	result[s1_length] = '\0';
	if (s1)
		free((void *)s1);
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		s_length;
	char	*dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	dup = malloc(sizeof(*s) * (s_length + 1));
	if (!dup)
		return (NULL);
	while (*s)
	{
		dup[i] = *s;
		i++;
		s++;
	}
	dup[i] = '\0';
	return (dup);
}

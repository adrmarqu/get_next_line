/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:22:02 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/23 12:00:33 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)b;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	b = (void *)a;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	s;
	void			*r;

	s = count * size;
	r = malloc(s);
	if (r == NULL)
		return (NULL);
	ft_memset(r, 0, s);
	return (r);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	int		s_size;
	char	*r;

	s_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = (char *)ft_calloc(s_size, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	free(s1);
	return (r);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:06:47 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/23 12:00:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*read_line(int fd, char *r)
{
	char	*buffer;
	int		num;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	num = 1;
	while (num > 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num] = '\0';
		r = ft_join(r, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (r);
}

char	*clean_line(char *buffer)
{
	char	*r;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	r = ft_calloc(i + 2, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		r[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		r[i] = '\n';
		i++;
	}
	return (r);
}

char	*next_buffer(char *buffer)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	r = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!r)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
	{
		r[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*buffer[300];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = clean_line(buffer[fd]);
	buffer[fd] = next_buffer(buffer[fd]);
	return (line);
}

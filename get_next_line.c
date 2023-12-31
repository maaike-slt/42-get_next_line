/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:40:27 by msloot            #+#    #+#             */
/*   Updated: 2023/12/31 16:11:46 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	first_newline(const char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*pos_bytes(char *buffer, int fd, ssize_t *n_bytes, char *line)
{
	ssize_t	new_line;

	buffer[*n_bytes] = '\0';
	new_line = first_newline(buffer);
	if (new_line >= 0)
	{
		buffer[new_line] = '\0';
		line = ft_strjoin_free(line, buffer, true, false);
		if (!line)
		{
			*n_bytes = -2;
			return (NULL);
		}
		buffer = ft_strcpy(buffer, &buffer[new_line + 1]);
		return (line);
	}
	line = ft_strjoin_free(line, buffer, true, false);
	if (!line)
	{
		*n_bytes = -2;
		return (NULL);
	}
	*n_bytes = read(fd, buffer, BUFFER_SIZE);
	return (NULL);
}

static char	*find_line(char *buffer, int fd)
{
	char	*line;
	ssize_t	n_bytes;

	if (buffer[0] == '\0')
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	line[0] = '\0';
	while (n_bytes > 0)
	{
		line = pos_bytes(buffer, fd, &n_bytes, line);
		if (line != NULL)
			return (ft_strjoin_free(line, "\n", true, false));
	}
	free(buffer);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (find_line(buffer, fd));
}

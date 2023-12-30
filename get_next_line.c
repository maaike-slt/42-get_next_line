/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:40:27 by msloot            #+#    #+#             */
/*   Updated: 2023/12/30 16:55:54 by msloot           ###   ########.fr       */
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

static char	*init_buffer(char *buffer)
{
	if (buffer != NULL)
		return (buffer);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

static char	*find_line(char *buffer, int fd)
{
	char	*line;
	ssize_t	n_bytes;
	ssize_t	new_line;

	if (buffer[0] == '\0')
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (n_bytes > 0)
	{
		buffer[n_bytes] = '\0';
		new_line = first_newline(buffer);
		if (new_line >= 0)
		{
	//   - put buffer in line, until \n, here is how:
	//   means that we split the buffer in 2:
	//   buffer: "hello\nbonj"
	//       '-> "hello" part 1
	// 	  '-> "bonj" part 2
	//   put part 1 in line (strjoin)
	//   put part 2 at the start of buffer:
	//     buffer: "hello\nbonj"
	// 	   '->  "bonj"
	//   - finaly: return line
		}
		else
		{
	// 	- put buffer in line (strjoin)
	//  - read buffer
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!init_buffer(buffer))
		return (NULL);
	return (NULL);
}

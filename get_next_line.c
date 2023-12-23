/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:40:27 by msloot            #+#    #+#             */
/*   Updated: 2023/12/23 13:22:05 by msloot           ###   ########.fr       */
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

static void	init_buffer(char *buffer)
{

}

/*
	buffer[?]
	read(fd, buffer, BUFFER_SIZE);
	need to fit BUFFER_SIZE -> buffer
	how much to malloc ??? for BUFFER_SIZE to fit into buffer?
*/

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	
	return (NULL);
}

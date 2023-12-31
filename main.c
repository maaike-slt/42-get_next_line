/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:35:15 by msloot            #+#    #+#             */
/*   Updated: 2023/12/31 17:05:34 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac < 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	printf("fd:\t%d\n\n", fd);

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}

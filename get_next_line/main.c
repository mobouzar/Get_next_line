/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:22:58 by mobouzar          #+#    #+#             */
/*   Updated: 2019/05/01 05:24:18 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text", O_RDONLY);
	while ((i = (get_next_line(fd, &line))))
	{
		printf("%d\n", i);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}

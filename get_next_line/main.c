/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:22:58 by mobouzar          #+#    #+#             */
/*   Updated: 2019/05/07 00:31:26 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd;
	char	*line;
	int		i;
	int		c = 1;

	fd = open("text", O_RDONLY);
	while ((i = (get_next_line(fd, &line))) == 1)
	{
		printf("%d = %s\n", c, line);
		c++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

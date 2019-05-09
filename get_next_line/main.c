/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:22:58 by mobouzar          #+#    #+#             */
/*   Updated: 2019/05/08 20:56:39 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int 	fd1;
	char	*line;
	int		i;

	fd1 = open(argv[1], O_RDONLY);

	argc = 1;
		while (i < 10)
		{
			a = get_next_line(fd1, &line);
			printf("%d = %s\n", c, line);
			i++;
			ft_strdel(&line);
		}
		ft_strdel(&line);
	lose(fd1);
	return (0);
}

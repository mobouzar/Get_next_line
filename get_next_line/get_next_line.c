/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:46:16 by mobouzar          #+#    #+#             */
/*   Updated: 2019/04/24 21:47:03 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int					get_next_line(const int fd, char **line)
{
	static char		*lineof[256];
	char			buff[BUFF_SIZE + 1];
	int				countchars;
	int				pos;

	pos = 0;
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!lineof[fd])
		lineof[fd] = ft_strnew(0);
		ft_strdel(lineof);
	while ((countchars = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[countchars] = '\0';
		lineof[fd] = ft_strjoin(lineof[fd], buff);
		if (ft_strchr(lineof[fd], '\n'))
			break ;
	}
	while (lineof[fd][pos] != '\n' && lineof[fd][pos] != '\0')
		pos++;
	*line = ft_strsub(lineof[fd], 0, pos);
	if (ft_strlen(lineof[fd]) == 0 && pos == 0 && countchars == 0)
		return (0);
	lineof[fd] = ft_strdup(lineof[fd] + pos + 1);
	return (1);
}

int	main()
{
	int fd1 = open("anas", O_RDONLY);
	int fd2 = open("text", O_RDONLY);

	char *line;
	int i;
	int c = 0;
// while (1)
// {
	// while ((i = (get_next_line(fd1, &line))))
	// {
	// 	c++;
	// 	//printf("%d\n", c);
	// 	printf("%s\n", line);
	// 	free(line);

	// }
// }
	get_next_line(fd1, &line);
	ft_putendl(line);

	get_next_line(fd2, &line);
	ft_putendl(line);

	get_next_line(fd1, &line);
	ft_putendl(line);

	get_next_line(fd2, &line);
	ft_putendl(line);

	get_next_line(fd1, &line);
	ft_putendl(line);

	return (0);
}
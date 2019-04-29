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

int		get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				countchar;
	int				i;

	if (!line || (read(fd, buff, 0) < 0))
		return (-1);
	*line = ft_strdup("\0");
	if (buff[0])
		*line = ft_strjoin(*line, buff);
	while ((countchar = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[countchar] = '\0';
		*line = ft_strjoin(*line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	i = 0;
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	ft_strcpy(buff, ft_strsub(*line, i + 1, ft_strlen(*line)));
	if (countchar == 0)
		return (0);
	line[0][i] = '\0';
	return (1);
	free(line);
}

int	main()
{
	int fd = open("text", O_RDONLY);
	char *line;
	int i;
	int c = 0;
// while (1)
// {
	while ((i = (get_next_line(fd, &line))))
	{
		c++;
		//printf("%d\n", c);
		printf("%s\n", line);
		free(line);

	}
// }	
	return (0);
}
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

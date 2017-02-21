/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 19:55:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_into_buffer(int fd, char **buffer)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	*buffer = ft_strjoin(*buffer, buff);
	return (ret);
}

static	int		get_next(int fd, char **buffer, char **line)
{
	char	*eol;
	int		read;

	read = read_into_buffer(fd, buffer);
	if (read == -1)
		return (-1);
	eol = ft_strchr(*buffer, '\n');
	if (!eol && read)
		get_next(fd, buffer, line);
	if (eol)
	{
		*line = ft_strsub(*buffer, 0, (eol - *buffer));
		*buffer = eol + 1;
		return (1);
	}
	if (!read && !eol && **buffer)
	{
		*line = ft_strdup(*buffer);
		printf("buffer %s\n", *buffer);
		printf("line %s\n", *line);
		**buffer = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static	char	*buffer;

	if (fd < 0)
		return (-1);
	if (!buffer)
	{
		if (!(buffer = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	//printf("%d\n", get_next(fd, &buffer, line));
	return (get_next(fd, &buffer, line));
}

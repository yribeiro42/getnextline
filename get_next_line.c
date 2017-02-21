/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/02/21 16:12:08 by anonymous        ###   ########.fr       */
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

	while ((read = read_into_buffer(fd, buffer)) > 0)
	{
		if (read < 0)
			return (-1);
		if ((eol = ft_strchr(*buffer, '\n')))
			break;
	}
	if (read < BUFF_SIZE && !ft_strlen(*buffer))
		return (0);
	if (eol)
	{
		*line = ft_strsub(*buffer, 0, (eol - *buffer));
		*buffer = eol + 1;
	}
	if (!eol)
	{
		*line = ft_strdup(*buffer);
		ft_strclr(*buffer);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static	char	*buffer;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!buffer)
	{
		if (!(buffer = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	return (get_next(fd, &buffer, line));
}

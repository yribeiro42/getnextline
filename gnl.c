/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/01 14:21:54 by yribeiro         ###   ########.fr       */
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

	while (!(eol = ft_strchr(*buffer, '\n')) &&
		(read = read_into_buffer(fd, buffer)) > 0)
	{
		if (read < 0)
			return (-1);
	}
	if (read < BUFF_SIZE && !ft_strlen(*buffer))
	{
		ft_strclr(*buffer);
		if (*line)
			ft_strdel(line);
		return (0);
	}
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
	int				ret;

	if (fd < 0)
		return (-1);
	if (!buffer)
	{
		if (!(buffer = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	ret = get_next(fd, &buffer, line);
	if (*line == NULL)
		return (-1);
	return (ret);
}

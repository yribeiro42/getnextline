/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:30:16 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/01 14:22:03 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		get_next(int fd, char **buffer, char **line)
{
	char	*eol;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while (!(eol = ft_strchr(*buffer, '\n')) &&
			(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*buffer = ft_strjoin(*buffer, buff);
		if (ret < 0)
			return (-1);
	}
	if (ret < BUFF_SIZE && !ft_strlen(*buffer))
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

	if (fd < 0 || !line)			//fix
		return (-1);
	if (!buffer)
		buffer = ft_strnew(1);
	ret = get_next(fd, &buffer, line);
	if (*line == NULL)
		return (-1);
	return (ret);
}

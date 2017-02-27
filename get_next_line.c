/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/02/27 13:04:35 by yribeiro         ###   ########.fr       */
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
		//printf(MAG "%s\n" RESET, *buffer);
		if (read < 0)
			return (-1);
		if ((eol = ft_strchr(*buffer, '\n')))
			break ;
	}
	if (read < BUFF_SIZE && !ft_strlen(*buffer))
	{
		return (0);
	}
	if (eol)
	{
		*line = ft_strsub(*buffer, 0, (eol - *buffer));
		*buffer = eol + 1;
		//printf(GRN "line = %s\n" RESET, *line);
		//printf(RED "buffer = %s\n" RESET, *buffer);
	}
	if (!eol)
	{
		*line = ft_strdup(*buffer);
		free(*buffer);
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
		buffer = ft_strnew(1);
	ret = get_next(fd, &buffer, line);
	if (*line == NULL)
		return (-1);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:29 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/28 20:16:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*get_next_fd(int fd, t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(head, tmp);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	t_list	static	*list;
	t_list			*head;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	head = list;
	list = get_next_fd(fd, &head);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		list->content = ft_strjoin(list->content, buffer);
		if (ft_strchr(buffer, EOL))
			break ;
	}
	ret = 0;
	while (((char *)list->content)[ret] != EOL && ((char *)list->content)[ret])
		ret++;
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == EOL)
		ret++;
	list->content = ft_strdup(list->content + ret);
	list = head;
	return (ret ? 1 : 0);
}

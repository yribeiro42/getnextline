/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:29 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/30 17:27:37 by yribeiro         ###   ########.fr       */
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

char		*get_next_free(char *content, char *buffer)
{
	char *tmp;

	tmp = content;
	content = ft_strjoin(content, buffer);
	free(tmp);
	return (content);
}

char 		*get_last_free(char **content, int ret)
{
	char *tmp;

	tmp = *content;
	*content = ft_strdup(*content + ret);
	free(tmp);
	return (*content);
}

int			get_next_line(int fd, char **line)
{
	t_list	static	*list;
	t_list			*head;
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	head = list;
	list = get_next_fd(fd, &head);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		list->content = get_next_free(list->content, buffer);
		if (ft_strchr(buffer, EOL))
			break ;
	}
	ret = 0;
	while (((char *)list->content)[ret] != EOL && ((char *)list->content)[ret])
		++ret;
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == EOL)
		ret++;
	tmp = list->content;
	list->content = ft_strdup(list->content + ret);
	free(tmp);
	list = head;
	return (ret ? 1 : 0);
}

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

int		get_next_line(int fd, char **line)
{
	t_list	static	*curr;
	t_list			*head;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (!line || fd < 0)
		return (-1);
	head = curr;
	curr  = get_next_fd(fd, &head);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		curr->content = ft_strjoin(curr->content, buffer);
		if (ft_strchr(buffer, EOL))
			break ;
	}
	ret = 0;
	while (((char *)curr->content)[ret] && ((char *)curr->content)[ret] != EOL)
		ret++;
	*line = strndup(curr->content, ret);
	if (((char *)curr->content)[ret] == EOL)
		ret++;
	curr->content = ft_strdup(curr->content + ret);
	curr = head;
	return (ret ? 1 : 0);
}

#include "get_next_line.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*str;
	int		nbr;
	char	*d;

	nbr = ft_strlen(s1) + ++len;
	str = ft_strnew(nbr);
	d = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - d));
}

static t_list	*ft_findfd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_freejoin(char *tmp, char *buf, int ret)
{
	char	*l;

	l = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	free(l);
	return (tmp);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*l;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = list;
	list = ft_findfd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		list->content = ft_freejoin(list->content, buf, ret);
	ret = 0;
	while (((char *)list->content)[ret] && ((char *)list->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == '\n')
		++ret;
	l = list->content;
	list->content = ft_strdup(list->content + ret);
	free(l);
	list = begin;
	return (ret ? 1 : 0);
}
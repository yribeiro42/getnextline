#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*copy;

	copy = malloc(sizeof(char) * ft_strlen(n));
	if !(copy)
		return (NULL);
	ft_strncpy(copy, s, n);
	return (copy);
}

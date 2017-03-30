/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:05:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/30 17:57:05 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
    char    *ret;
    size_t    i;

    if (!(ret = ft_strnew(ft_strlen(s))))
        return (NULL);
    i = 0;
    while (s[i])
    {
        ret[i] = s[i];
        i++;
    }
    return (ret);
}
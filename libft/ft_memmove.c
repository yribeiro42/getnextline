/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:50:22 by yribeiro          #+#    #+#             */
/*   Updated: 2016/11/15 16:09:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmpdest;
	unsigned char		*tmpsrc;
	size_t				i;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (unsigned char*)src;
	i = 0;
	if (tmpsrc < tmpdest)
	{
		while (n--)
			tmpdest[n] = tmpsrc[n];
	}
	else
	{
		while (i < n)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (dest);
}

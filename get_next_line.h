/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:30:16 by yribeiro          #+#    #+#             */
/*   Updated: 2017/03/30 18:31:18 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

# define BUFF_SIZE 100
# define EOL	'\n'

int		get_next_line(const int fd, char **line);

// !(ft_strchr(buffer, EOL)) && //

#endif

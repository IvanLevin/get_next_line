/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:33:16 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/26 14:18:29 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 11000
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

# define MRES(a, b) { if(!a || !b) return (-1); else return (1);}

#endif

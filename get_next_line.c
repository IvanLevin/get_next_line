/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:36:14 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/26 17:43:08 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*get_starr(char **starr, char *line, int fd)
{
	char *buffer;

	buffer = NULL;
	if (ft_strlen(line) < ft_strlen(starr[fd]))
	{
		buffer = starr[fd];
		starr[fd] = ft_strdup(ft_strchr(starr[fd], '\n') + 1);
		free(buffer);
		return (starr[fd]);
	}
	else
	{
		free(starr[fd]);
		starr[fd] = ft_strdup("");
		return (starr[fd]);
	}
	return (0);
}

static	char	*get_line(char **starr, char *line, int fd)
{
	int	i;

	i = 0;
	while (starr[fd][i] != '\n' && starr[fd][i] != '\0')
		i++;
	if (i == 0)
	{
		if (!(line = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		if (!(line = ft_strnew(i)))
			return (NULL);
		line = ft_strncpy(line, starr[fd], i);
	}
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static char	*starr[4864];
	char		buf[BUFF_SIZE + 1];
	char		*arr;
	int			n;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (starr[fd] == NULL)
		starr[fd] = ft_strnew(0);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		arr = ft_strjoin(starr[fd], buf);
		free(starr[fd]);
		starr[fd] = arr;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((n < BUFF_SIZE && !ft_strlen(starr[fd])))
		return (0);
	MRES((*line = get_line(starr, *line, fd)),
		(starr[fd] = get_starr(starr, *line, fd)));
	return (1);
}

 int		main(void)
 {
 	int		fd;
 	int		fd2;
 	char	*line;
 	int		b;

 	line = NULL;
 	fd = open("/Users/gkshleri/Documents/Projects/get_next_line/large_file.txt", O_RDONLY);
 	// fd2 = open("/Users/gkshleri/Documents/Projects/get_next_line/some_2.txt", O_RDONLY);
 	// fd2 = open("/Users/gkshleri/Documents/Projects/get_next_line/some_2.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);
 		// b = get_next_line(-10000, &line);
 		// printf("return: %d | %s \n", b, line);
 		// b = get_next_line(fd2, &line);
 		// printf("fd2 | return: %d | %s \n", b, line);
 		// b = get_next_line(fd, &line);
 		// printf("return: %d | %s \n", b, line);
 		// b = get_next_line(fd2, &line);
 		// printf("fd2 | return: %d | %s \n", b, line);
 		// b = get_next_line(fd, &line);
 		// printf("return: %d | %s \n", b, line);
 		// b = get_next_line(fd2, &line);
 		// printf("fd2 | return: %d | %s \n", b, line);
 		// b = get_next_line(fd, &line);
 		// printf("return: %d | %s \n", b, line);
 		// b = get_next_line(fd2, &line);
 		// printf("%s \n", line);
 		// b = get_next_line(fd, &line);
 		// printf("%s \n", line);

 		while ((b = get_next_line(fd, NULL)))
 		{
 			// write(fd2, line, ft_strlen(line));
 			// write(fd2, "\n", 1);
 			printf("return %d | ", b);
 			printf("%s\n", line);
 			ft_strdel(&line);
 		}
 		printf("return %d | ", b);
 		printf("%s\n", line);
 	close(fd);
 	return (0);
 }

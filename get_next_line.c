/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 14:16:07 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/22 17:12:08 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "main.h"

static size_t	get_line_status(char *line)
{
	size_t	i;

	i = 0;
	while (*(line + i) != '\0' && *(line + i) != '\n')
		i++;
	if (i != BUFFER_SIZE + 1)
	{
		if (*(line + i) == '\0')
			return (-i);
		else if (*(line + i) == '\n')
			return (i);
	}
	return (0);
}

static int		set_line(char **line, char *buff)
{
	size_t	i;
	size_t	len_buff;
	size_t	len_line;

	i = 0;
	len_buff = ft_strlen_plus(buff);
	len_line = ft_strlen(*line);
	*line = (char*)ft_realloc(*line, len_line + len_buff);
	while (i < len_buff)
	{
		*(*line + i + len_line) = buff[i];
		i++;
	}
	return (i);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	int			status;
	int			i;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	ret = 0;
	status = 0;
	buff[0] = '\0';
	*line = (char*)malloc(1);
	*line[0] = '\0';
	i = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		i = set_line(line, buff);
		status = get_line_status(buff);
	}
	fd = fd - abs(status) + i;
	if (status < 0)
		return (0);
	return (1);
}

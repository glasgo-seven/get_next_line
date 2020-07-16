/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:19 by sanakin           #+#    #+#             */
/*   Updated: 2020/07/15 17:54:40 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "main.h"

static size_f	check_buff(char *buff)
{
	size_f	i;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0' && i != BUFFER_SIZE)
		return (-(i + 1));
	if (buff[i] == '\n')
		return (i + 1);
	return (0);
}

static char		*get_line(char *buff, size_t len)
{
	char	*new_line;
	size_t	i;

	i = 0;
	new_line = (char*)malloc(sizeof(char*) * len + 1);
	if (!new_line)
		return(NULL);
	while (i < len)
	{
		new_line[i] = buff[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static size_f	check_leftovers(char *leftovers, char **line)
{
	size_t	i;
	
	if (!leftovers)
		return (0);
/*
	ft_putstr("\nLEFT=[");
	ft_putstr(leftovers);
	ft_putstr("]");
*/
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\0' && i != ft_strlen(leftovers))
	{
		*line = ft_substr(leftovers, 0, i);
		return (-(i + 1));
	}
	if (leftovers[i] == '\n')
	{
		*line = ft_substr(leftovers, 0, i);
		return (i + 1);
	}
	return (0);
}
/*
int				get_next_line_input(char **line)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	static char	*input_lines;

	ret = 0;
	*input_lines = ft_strdup("\0");
	while ((ret = read(1, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		ft_strjoin_len(input_lines, buff, BUFFER_SIZE);
	}
	
}
*/
int				get_next_line(int fd, char **line)
{
	/*
		1. read first line
		2. read second line
		3. read lines from separete files
	*/
	static char	*leftovers;
	int			ret;
	char		*buff;
	size_f		status;
	
	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	buff = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1));
	if (fd != 1 && read(fd, buff, 0) < 0)
		return (-1);
	
	*line = ft_strdup("\0");
	status = check_leftovers(leftovers, line);
	
	if (status == 0)
	{
		if (leftovers && ft_strlen(leftovers) != 0)
		{
			*line = ft_strdup(leftovers);
			leftovers = ft_strdup("\0");
		}
		while (status == 0)
		{
			ret = read(fd, buff, BUFFER_SIZE);
			buff[ret] = '\0';
			status = check_buff(buff);
	/*
			ft_putstr("\n\nret=");
			ft_putnbr(ret);
			ft_putstr("\nbuff=");
			ft_putstr(buff);
			ft_putstr("\nstatus=");
			ft_putnbr(status);
			ft_putstr("\n\nLINE=[");
			ft_putstr(*line);
			ft_putstr("]");
			ft_putstr("\nline=[");
			ft_putstr(get_line(buff, BUFFER_SIZE));
			ft_putstr("]");
	*/
			if (status == 0)
				*line = ft_strjoin_len(*line, buff, BUFFER_SIZE);
			else
				*line = ft_strjoin_len(*line, get_line(buff, ft_abs(status) - 1), ft_abs(status));
	/*
			ft_putstr("\nLINE*=[");
			ft_putstr(*line);
			ft_putstr("]\n");
	*/
		}
		leftovers = ft_substr(buff, ft_abs(status), BUFFER_SIZE - ft_abs(status));
	}
	else
	{
		leftovers = ft_substr(leftovers, ft_abs(status), ft_strlen(leftovers) - ft_abs(status));
	}
/*
	ft_putstr("\nleft*=[");
	ft_putstr(leftovers);
	ft_putstr("]\n");
*/
	free(buff);
	if (status < 0)
		return (0);
	if (status > 0)
		return (1);
	return (-1);
}

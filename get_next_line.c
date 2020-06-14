/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 14:16:07 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/14 16:23:35 by sanakin          ###   ########.fr       */
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

static void		set_line(char **line, char *buff)
{
	size_t	i;
	size_t	len_buff;
	size_t	len_line;

	i = 0;
	
	//ft_putstr("- GETTING LEN_BUFF -\n");
	len_buff = ft_strlen_plus(buff);
	//ft_putstr("LEN_BUFF : ");
	//ft_putnbr(len_buff);
	//ft_putstr("\n");
	
	//ft_putstr("- GETTING LEN_LINE -\n");
	len_line = ft_strlen(*line);
	//ft_putstr("LEN_LINE : ");
	//ft_putnbr(len_line);
	//ft_putstr("\n");
	
	//ft_putstr("- CALLING REALLOC -\n");
	*line = (char*)ft_realloc(*line, len_line + len_buff);
	//ft_putstr("- REALLOC COMPLETE -\n");
	while (i < len_buff)
	{
		*(*line + i + len_line) = buff[i];
		i++;
	}
}

int				get_next_line(int fd, char **line)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	size_t	status;

	ret = 0;
	status = 0;
	buff[0] = '\0';
	*line = (char*)malloc(1);
	*line[0] = '\0';
	while (status == 0)
	{
		//ft_putstr("\nSTATUS : ");
		//ft_putnbr(status);
		//ft_putstr("\n");

		//ft_putstr("= SETTING UP LINE =\n");
		set_line(line, buff);
		
		//ft_putstr("= LINE READ =\n");
		ret = read(fd, buff, BUFFER_SIZE);
		*(buff + ret) = '\0';
		//ft_putstr("LINE : ");
		//ft_putstr(buff);
		
		status = get_line_status(buff);
		//ft_putstr("\nNEW STATUS : ");
		//ft_putnbr(status);
		//ft_putstr("\n");
	}
	
	//ft_putstr("= SETTING UP LINE =\n");
	set_line(line, buff);
	
	if (status < 0)
		return (0);
	if (status > 0)
		return (1);
	free(*line);
	return (-1);
}

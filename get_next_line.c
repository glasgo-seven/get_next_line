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

static size_f	check_leftovers(char *leftovers, char **line)
{
	size_t	i;
	
	if (!leftovers)
		return (0);
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\0' && i != ft_strlen(leftovers))
	{
		if (*line)
			free(*line);
		*line = ft_substr(leftovers, 0, i);
		return (-(i + 1));
	}
	if (leftovers[i] == '\n')
	{
		if (*line)
			free(*line);
		*line = ft_substr(leftovers, 0, i);
		return (i + 1);
	}
	return (0);
}

static void		onStatusZero()
{
	
}

int				get_next_line(int fd, char **line)
{
	static char	*leftovers;
	int			ret;
	char		*buff;
	char		*temp;
	char		*tmp;
	size_f		status;

	temp = NULL;
	tmp = NULL;
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
			if (*line)
				free(*line);
			*line = ft_strdup(leftovers);
			if (leftovers)
				free(leftovers);
			leftovers = ft_strdup("\0");
		}
		while (status == 0)
		{
			ret = read(fd, buff, BUFFER_SIZE);
			buff[ret] = '\0';
			status = check_buff(buff);
			if (status == 0)
			{
				temp = *line;
				if (!(*line = ft_strjoin_len(*line, buff, BUFFER_SIZE)))
					return (-1);
				if (temp)
					free(temp);
			}
			else
			{
				temp = *line;
				tmp = ft_substr(buff, 0, ft_abs(status) - 1);
				//tmp = get_line(buff, ft_abs(status) - 1);
				if (!(*line = ft_strjoin_len(*line, tmp, ft_abs(status))))
				{
					if (tmp)
						free(tmp);
					return (-1);
				}
				if (tmp)
					free(tmp);
				if (temp)
					free(temp);
			}
		}
		if (leftovers)
			free(leftovers);
		leftovers = ft_substr(buff, ft_abs(status), BUFFER_SIZE - ft_abs(status));
	}
	else
	{
		tmp = leftovers;
		leftovers = ft_substr(leftovers, ft_abs(status), ft_strlen(leftovers) - ft_abs(status));
		if (tmp)
			free(tmp);
	}
	free(buff);
	if (status < 0)
		return (0);
	if (status > 0)
		return (1);
	return (-1);
}

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

static t_size_f	check_buff(char *buff)
{
	t_size_f	i;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0' && i != BUFFER_SIZE)
		return (-(i + 1));
	if (buff[i] == '\n')
		return (i + 1);
	return (0);
}

static t_size_f	check_leftovers(char *leftovers, char **line)
{
	size_t	i;

	if (!leftovers)
		return (0);
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\0' && i != ft_strlen(leftovers))
	{
		ft_free((void**)line);
		*line = ft_substr(leftovers, 0, i);
		return (-(i + 1));
	}
	if (leftovers[i] == '\n')
	{
		ft_free((void**)line);
		*line = ft_substr(leftovers, 0, i);
		return (i + 1);
	}
	return (0);
}

static int		set_status(char *buf, char **line, t_size_f *status, char **tmp)
{
	char	*temp;

	temp = NULL;
	*status = check_buff(buf);
	if (*status == 0)
	{
		temp = *line;
		if (!(*line = ft_strjoin_len(*line, buf, BUFFER_SIZE)))
			return (-1);
		ft_free((void**)&temp);
	}
	else
	{
		temp = *line;
		*tmp = ft_substr(buf, 0, f_abs(*status) - 1);
		if (!(*line = ft_strjoin_len(*line, *tmp, f_abs(*status))))
		{
			ft_free((void**)tmp);
			return (-1);
		}
	}
	ft_free((void**)tmp);
	return (ft_free((void**)&temp));
}

static int		on_status_zero(char **leftovers,
							char **line, int fd, t_size_f *status)
{
	char	*buff;
	char	*tmp;
	int		ret;

	ret = 0;
	buff = NULL;
	tmp = NULL;
	if (!(buff = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1))))
		return (-1);
	if (*leftovers && ft_strlen(*leftovers) != 0)
	{
		ft_free((void**)line);
		*line = ft_substr(*leftovers, 0, ft_strlen(*leftovers));
		ft_free((void**)leftovers);
	}
	while (*status == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		if (set_status(buff, line, status, &tmp) < 0)
			return (-1);
	}
	ft_free((void**)leftovers);
	*leftovers = ft_substr(buff, f_abs(*status), BUFFER_SIZE - f_abs(*status));
	return (ft_free((void**)&buff));
}

int				get_next_line(int fd, char **line)
{
	static char	*left;
	char		*buf;
	char		*temp;
	t_size_f	status;

	temp = NULL;
	if (BUFFER_SIZE < 1 || !line || fd < 0 ||
	!(buf = (char*)malloc(sizeof(char*))) || (fd != 1 && read(fd, buf, 0) < 0))
		return (-1);
	ft_free((void**)&buf);
	*line = NULL;
	if ((status = check_leftovers(left, line)) == 0)
	{
		if (on_status_zero(&left, line, fd, &status) == -1)
			return (-1);
	}
	else
	{
		temp = left;
		left = ft_substr(left, f_abs(status), ft_strlen(left) - f_abs(status));
		ft_free((void**)&temp);
	}
	if (status < 0)
		return (0);
	return (status > 0) ? (1) : (-1);
}

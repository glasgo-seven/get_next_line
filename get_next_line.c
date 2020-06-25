/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 14:16:07 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/25 14:33:54 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_abs(size_f nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}

static size_f	get_status(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' && i != ft_strlen(str))
		return (-i);
	if (str[i] == '\n')
		return (i);
	return (0);
}

static char		*get_leftovers(t_fd_list *fd_list, int fd)
{
	t_fd_list	*lst;

	lst = fd_list;
	while (lst)
		if (lst->fd == fd)
			return (lst->leftovers);
		else
			lst = lst->next;
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	static t_fd_list	*fd_list;
	char				buff[BUFFER_SIZE + 1];
	char				*new_line;
	int					ret;
	size_f				status;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!fd_list)
		fd_list = ft_fd_lstnew(fd);
	else if (!find_fd(fd_list, fd))
		ft_fd_lstadd_back(&fd_list, ft_fd_lstnew(fd));
	status = 0;
	while (status == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		status = get_status(buff);
		new_line = ft_strjoin_len(new_line, buff, ft_abs(status));
	}
	*line = new_line;
	free(new_line);
	return (status < 0 ? 0 : 1);
}

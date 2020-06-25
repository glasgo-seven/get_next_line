/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:05:56 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/25 14:40:00 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find_fd(t_fd_list *fd_list, int fd)
{
	t_fd_list	*lst;
	
	if (!fd_list)
		return (0);
	lst = fd_list;
	while (lst)
		if (lst->fd == fd)
			return (1);
		else
			lst = lst->next;
	return (0);
}

t_fd_list	*ft_fd_lstnew(int fd)
{
	t_fd_list	*list;

	list = (t_fd_list*)malloc(sizeof(t_fd_list));
	if (list == NULL)
		return (NULL);
	list->fd = fd;
	list->leftovers = NULL;
	list->next = NULL;
	return (list);
}

void	ft_fd_lstadd_back(t_fd_list **lst, t_fd_list *new)
{
	t_fd_list	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
	}
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_len(char const *s1, char const *s2, size_t len)
{
	char	*joined;
	size_t	s1_len;
	size_t	j_i;
	size_t	s_i;
	
	if (!s2)
		return (NULL);
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	joined = (char*)malloc((s1_len + len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	j_i = 0;
	s_i = 0;
	while (s1)
	{
		*(joined + j_i) = *(s1 + s_i);
		j_i++;
		s_i++;
	}
	s_i = 0;
	while (s2 && s_i < len)
	{
		*(joined + j_i++) = *(s2 + s_i);
		s_i++;
	}
	*(joined + j_i) = '\0';
	return (joined);
}

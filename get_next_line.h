/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:40:34 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/25 14:40:50 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 64

typedef long long int size_f;

typedef struct			s_fd_list
{
	int					fd;
	char				*leftovers;
	struct s_fd_list	*next;
}						t_fd_list;

int			find_fd(t_fd_list *fd_list, int fd);
t_fd_list	*ft_fd_lstnew(int fd);
void		ft_fd_lstadd_back(t_fd_list **lst, t_fd_list *new);

size_t		ft_strlen(const char *s);
char		*ft_strjoin_len(char const *s1, char const *s2, size_t len);

int			get_next_line(int fd, char **line);

#endif
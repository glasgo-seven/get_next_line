/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:40:34 by sanakin           #+#    #+#             */
/*   Updated: 2020/07/13 15:09:55 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	long long int	t_size_f;

size_t		f_abs(t_size_f nbr);
size_t		ft_strlen(const char *str);
int			ft_free(void **obj);
char		*ft_strjoin_len(char const *s1, char const *s2, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			get_next_line(int fd, char **line);

#endif

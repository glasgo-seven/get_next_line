/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:40:34 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/22 17:10:58 by sanakin          ###   ########.fr       */
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

int		ft_abs(int nbr);
int		ft_strlen(char *str);
int		ft_strlen_plus(char *str);
void	*ft_realloc(char *arr, size_t size);

int		get_next_line(int fd, char **line);

#endif
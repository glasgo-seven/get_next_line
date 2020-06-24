/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:05:56 by sanakin           #+#    #+#             */
/*   Updated: 2020/06/22 17:09:15 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int		ft_strlen_plus(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && *(str + i) != '\n')
		i++;
	return (i);
}

void	*ft_realloc(char *arr, size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = (char*)malloc(size + 1);
	while (i < size && arr[i] != '\0')
	{
		mem[i] = arr[i];
		i++;
	}
	while (i < size + 1)
	{
		mem[i] = '\0';
		i++;
	}
	return ((void*)mem);
}

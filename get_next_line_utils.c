/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanakin <sanakin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:25 by sanakin           #+#    #+#             */
/*   Updated: 2020/07/06 17:26:42 by sanakin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "main.h"

size_t		ft_abs(size_f nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char	*n_s;
	size_t	i;

	n_s = (char*)malloc(sizeof(*s) * (ft_strlen((char*)s) + 1));
	if (n_s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(n_s + i) = *(s + i);
		i++;
	}
	*(n_s + i) = '\0';
	return (n_s);
}

char		*ft_strjoin_len(char const *s1, char const *s2, size_t len)
{
	char	*joined;
	size_t	j_i;
	size_t	s_i;

	if (s2 == NULL)
		return (NULL);
/*
	ft_putstr("\n\nLINE_LEN=");
	ft_putnbr(ft_strlen((char*)s1));
	ft_putchar('\n');
*/
	joined = (char*)malloc((ft_strlen((char*)s1) + len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	j_i = 0;
	s_i = 0;
/*
	ft_putstr("\n\n\[ s1 ]");
*/
	while (s1[s_i] != '\0')
	{
/*
		ft_putstr("\n\nj=");
		ft_putnbr(j_i);
		ft_putstr("\ns=");
		ft_putnbr(s_i);
		ft_putstr("\nchar=");
		ft_putchar(*(s1 + s_i));
*/
		*(joined + j_i) = *(s1 + s_i);
		j_i++;
		s_i++;
	}
	s_i = 0;
/*
	ft_putstr("\n\n[ s2 ]");
*/
	while (s2 && s_i < len)
	{
/*
		ft_putstr("\n\nj=");
		ft_putnbr(j_i);
		ft_putstr("\ns=");
		ft_putnbr(s_i);
		ft_putstr("\nchar=");
		ft_putchar(*(s2 + s_i));
*/
		*(joined + j_i) = *(s2 + s_i);
		j_i++;
		s_i++;
	}
	*(joined + j_i) = '\0';
/*
	ft_putstr("\n\njoin=");
	ft_putstr(joined);
*/
	return (joined);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_s;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen((char*)s))
		len = 0;
	sub_s = (char*)malloc((len + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i) != '\0')
	{
		*(sub_s + i) = *(s + start + i);
		i++;
	}
	while (i < len + 1)
	{
		*(sub_s + i) = '\0';
		i++;
	}
	return (sub_s);
}

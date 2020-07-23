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

size_t		f_abs(t_size_f nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_free(void **obj)
{
	if (obj)
	{
		free(*obj);
		*obj = NULL;
	}
	return (0);
}

char		*ft_strjoin_len(char const *s1, char const *s2, size_t len)
{
	char	*joined;
	size_t	j_i;
	size_t	s_i;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_substr(s2, 0, len));
	if (!(joined = (char*)malloc((ft_strlen(s1) + len + 1) * sizeof(char*))))
		return (NULL);
	j_i = 0;
	s_i = 0;
	while (s1[s_i] != '\0')
	{
		*(joined + j_i) = *(s1 + s_i++);
		j_i++;
	}
	s_i = 0;
	while (s2 && s_i < len)
	{
		*(joined + j_i) = *(s2 + s_i++);
		j_i++;
	}
	*(joined + j_i) = '\0';
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

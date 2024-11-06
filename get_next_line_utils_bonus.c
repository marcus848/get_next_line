/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:07:27 by marcudos          #+#    #+#             */
/*   Updated: 2024/11/06 20:16:51 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*point;
	int		i;

	point = (char *)s;
	i = 0;
	while (point[i])
	{
		if (point[i] == (char) c)
			return (&point[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&point[i]);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		s_len;

	s_len = ft_strlen((char *) s);
	dup = (char *) malloc(sizeof(char) * (s_len + 1));
	if (!dup)
		return (NULL);
	if (!s)
		return (NULL);
	ft_memcpy(dup, s, s_len);
	dup[s_len] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_join = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	ft_memcpy(str_join, s1, len_s1);
	ft_memcpy(&str_join[len_s1], s2, len_s2);
	str_join[len_s1 + len_s2] = '\0';
	return (str_join);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}

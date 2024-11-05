/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:07:27 by marcudos          #+#    #+#             */
/*   Updated: 2024/10/30 18:07:29 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

int	ft_strlen(char *s)
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
	int		i;

	s_len = ft_strlen((char *) s);
	dup = (char *) malloc(sizeof(char) * (s_len + 1));
	if (dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	int		len_s1;
	int		len_s2;
	int		x;
	int		y;

	y = 0;
	x = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_join = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	while (s1[x])
	{
		str_join[x] = s1[x];
		x++;
	}
	while (s2[y])
		str_join[x++] = s2[y++];
	str_join[x] = '\0';
	return (str_join);
}
//
// char	*ft_substr(char const *str, unsigned int start, size_t len)
// {
// 	char	*sub_str;
// 	size_t	str_len;
//
// 	if (!str)
// 		return (NULL);
// 	str_len = ft_strlen((char *)str);
// 	if (start >= str_len)
// 		return (ft_strdup(""));
// 	if (len + start > str_len)
// 		len = str_len - start;
// 	sub_str = (char *) ft_calloc(len + 1, sizeof(char));
// 	if (!sub_str)
// 		return (NULL);
// 	while (--len)
// 		sub_str[len] = str[start + len];
// 	return (sub_str);
// }

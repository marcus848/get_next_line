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

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
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
	int	s_len;
	int	i;

	s_len = ft_strlen((char *) s);
	dup = (char *) malloc(sizeof(char) * (s_len + 1));
	if (dup)
		return(NULL);
	i = 0;
	while (s[i++])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

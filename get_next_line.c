/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:48:15 by marcudos          #+#    #+#             */
/*   Updated: 2024/10/30 16:48:16 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_verify_res(char *res, char **line)
{
	if (res)
	{
		*line = ft_strdup(res);
		free(res);
	}
	else
		*line = ft_strdup("");
}

char	*ft_make_join(char *s1, char *s2)
{
	char	*str_join;

	str_join = ft_strjoin(s1, s2);
	free(s1);
	return (str_join);
}

void	ft_separate_str_line(char *s)
{
	*s = '\0';
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*res;
	char		*line;
	int			bytes_read;
	
	line = NULL;
	ft_verify_res(res, &line);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			ft_separate_str_line(ft_strchr(buf, '\n'));
			line = ft_make_join(line, buf);
			res = ft_strdup(ft_strchr(buf, '\n') + 1);
			free (buf);
			return (line);
		}
		line = ft_make_join(line, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	return (line);
}

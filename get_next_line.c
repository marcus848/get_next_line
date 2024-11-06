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

char	*ft_make_join(char *s1, char *s2)
{
	char	*str_join;
	
	if (!s1 || !s2)
		return (NULL);
	str_join = ft_strjoin(s1, s2)
	if (!str_join)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	return (str_join);
}

void	ft_change_res(char **res, char *newline_pos)
{
	char	*temp;

	if (newline_pos && *(newline_pos + 1) != '\0')
	{
		temp = ft_strdup(newline_pos + 1);
		if (!temp)
		{
			free(*res);
			*res = NULL;
			return ;
		}
		free(*res);
		*res = temp;
	}
	else
	{
		free(*res);
		*res = NULL;
	}
}

char	*ft_make_line(int fd, char **res, char *buf, char *line)
{
	int	size_read;
	char	*newline_pos;
	
	if (*res)
	{
		line = ft_make_join(line, *res);
		if (!line)
			return (NULL);
		ft_change_res(res, ft_strchr(*res, '\n'));
		if (!*res)
			return (NULL);
	}
	size_read = read(fd, buf, BUFFER_SIZE);
	while (size_read > 0)
	{
		buf[size_read] = '\0';
      		newline_pos = ft_strchr(buf, '\n');
		if (newline_pos)
		{
			line = ft_make_join(line, buf);
			if (!line)
				return (NULL);
			ft_change_res(res, newline_pos);
			if (!res)
				return (NULL);
			free(buf);
			return (line);
		}
		if (ft_strlen(line) == 0)
		{
			line = ft_strdup(buf);
			if (!line)
				return (NULL);
		}
		else
		{
			line = ft_make_join(line, buf);
			if (!line)
				return (NULL);
		}
		size_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (size_read == 0 && line[0] == '\0')
		return(NULL);
	return (line);
}



char	*get_next_line(int fd)
{
	char		*buf;
	static char	*res;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = ft_strdup("");
	if (!line)
	{
		free(buf);
		return (NULL);
	}
	line = ft_make_line(fd, &res, buf, line);
	if (!line)
		free(buf);
	return (line);
}

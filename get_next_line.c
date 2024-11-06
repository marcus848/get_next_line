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

char	*find_next_line(char *line)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	next_line = (char *) malloc((ft_strlen(line) - i) + 1);
	if (!next_line)
		return (free(line), NULL);
	i++;
	j = 0;
	while (line[i])
		next_line[j++] = line[i++];
	next_line[j] = '\0';
	free(line);
	return (next_line);
}

char	*find_current_line(char *line)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	current_line = (char *) malloc(i + 1);
	if (!current_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		current_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		current_line[i++] = '\n';
	current_line[i] = '\0';
	return (current_line);
}

char	*get_full_line(int fd, char *line)
{
	char	*buf;
	char	*temp;
	int		size_read;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(line), line = NULL);
	size_read = 1;
	while (size_read > 0 && !ft_strchr(line, '\n'))
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read < 0)
			return (free(buf), free(line), line = NULL);
		if (size_read == 0)
			break ;
		buf[size_read] = '\0';
		temp = ft_strjoin(line, buf);
		free(line);
		line = temp;
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	line = get_full_line(fd, line);
	if (!line)
		return (NULL);
	current_line = find_current_line(line);
	line = find_next_line(line);
	return (current_line);
}

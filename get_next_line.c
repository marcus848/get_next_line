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

char	*ft_substr(char *str, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = (char *) malloc((len + 1) * sizeof(char));
	while (len--)
		substr[i++] = *str++;
	substr[i] = '\0';
	return (substr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			size_read;
	int			find_new_line;

	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	find_new_line = -1;
	while (find_new_line == -1)
	{
		size_read = read(fd, buffer, BUFFER_SIZE - 1);
		if (size_read == -1)
			return (NULL);
		if (size_read == 0)
			return (NULL);
		find_new_line = ft_strchr(buffer, '\n');
		if (find_new_line == -1)
		{
			temp = line;
			line = ft_strjoin(line, buffer);
			free(temp);
		}
		else if

	}
	return (buffer);
}

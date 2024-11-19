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

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	current_line = construct_line(list);
	if (!current_line)
	{
		free_nodes(&list, NULL, NULL);
		return (NULL);
	}
	clean_list(&list);
	if (*current_line == '\0')
		return (free(current_line), NULL);
	return (current_line);
}

int	calculate_line_len(t_list *list)
{
	int	len;
	int	i;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		size_read;

	while (!found_new_line(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buf);
			free_nodes(list, NULL, NULL);
			return ;
		}
		if (size_read == 0)
		{
			free(buf);
			return ;
		}
		buf[size_read] = '\0';
		append_node(list, buf);
	}
}

char	*construct_line(t_list *list)
{
	char	*current_line;
	int		line_len;

	if (list == NULL)
		return (NULL);
	line_len = calculate_line_len(list);
	current_line = malloc(line_len + 1);
	if (!current_line)
		return (NULL);
	copy_current_line(list, current_line);
	return (current_line);
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*next_node;
	char	*next_line;
	int		i;
	int		k;

	if (!list)
		return ;
	next_line = malloc(BUFFER_SIZE + 1);
	next_node = malloc(sizeof(t_list));
	if (!next_node || !next_line)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i])
		next_line[k++] = last_node->content[++i];
	next_line[k] = '\0';
	next_node->content = next_line;
	next_node->next = NULL;
	free_nodes(list, next_node, next_line);
}

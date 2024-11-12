/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:18:15 by marcudos          #+#    #+#             */
/*   Updated: 2024/11/01 19:32:36 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
// get_next_line
char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
int	calculate_line_len(t_list *list);
char	*construct_line(t_list *list);
void	split_node_at_newline(t_list *list);
// get_next_line_utils
int	found_new_line(t_list *list);
void	append_node(t_list **list, char *buf);
t_list	*find_last_node(t_list	*list);
void	free_nodes(t_list **list);
void	copy_current_line(t_list *list, char *current_line);

#endif

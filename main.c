/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:17:38 by marcudos          #+#    #+#             */
/*   Updated: 2024/11/01 19:17:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    	int fd;
    	char *line;
	printf("Inicio:\n");
    
    	fd = open("teste.txt", O_RDONLY);
    	if (fd == -1)
    	{
       		perror("Error opening file");
        	return (1);
    	}
    	while ((line = get_next_line(fd)) != NULL)
    	{
        	printf("%s", line); // Removi o \n extra, pois o get_next_line já deve retornar a linha com o \n
        	free(line);
    	}
    		close(fd);
    		return (0);
}

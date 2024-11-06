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
	int fd2;
	int fd3;
	int i;
	char *line;
	printf("Inicio:\n");
    	printf("Teste 1:\n");
    	fd = open("teste.txt", O_RDONLY);
	fd2 = open("teste2.txt", O_RDONLY);
	fd3 = open("teste3.txt", O_RDONLY);
    	if (fd == -1 || fd2 == -1 || fd3 == -1)
    	{
		perror("Error opening file");
		return (1);
    	}
	i = 1;
    	while ((line = get_next_line(fd)) != NULL)
    	{
        	printf("teste1 >>> line %d: %s\n", i, line); // Removi o \n extra, pois o get_next_line já deve retornar a linha com o \n
        	free(line);
		i++;
    	}
	i = 1;
    	while ((line = get_next_line(fd2)) != NULL)
    	{
        	printf("teste2 >>> line %d: %s\n", i, line); // Removi o \n extra, pois o get_next_line já deve retornar a linha com o \n
        	free(line);
		i++;
	}
    	i = 1;
    	while ((line = get_next_line(fd3)) != NULL)
    	{
        	printf("teste3 >>> line %d: %s\n", i, line); // Removi o \n extra, pois o get_next_line já deve retornar a linha com o \n
        	free(line);
		i++;
    	}

    	close(fd);
	close(fd2);
	close(fd3);
    	return (0);
}

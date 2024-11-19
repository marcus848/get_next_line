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
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int     fd1, fd2, fd3;
    char    *line;
    int     line_num;

    printf(">>>>> Iniciando o tester <<<<<\n");
    printf(">>> BUFFER_SIZE = %d\n", BUFFER_SIZE);
    if (argc > 1 && strcmp(argv[1], "-bonus") == 0)
    {
        // Abrir os arquivos
        fd1 = open("test1.txt", O_RDONLY);
        fd2 = open("test2.txt", O_RDONLY);
        fd3 = open("test3.txt", O_RDONLY);

        if (fd1 < 0 || fd2 < 0 || fd3 < 0)
        {
            perror("Erro ao abrir arquivos");
            return (1);
        }

        // Ler e imprimir as linhas intercaladas dos arquivos test1.txt, test2.txt e test3.txt
        printf("\n--- Testando múltiplos FDs ---\n");
        int finished = 0;
        line_num = 1;
        while (!finished)
        {
            finished = 1;
            printf("\n--- Conteudo linha %d ---\n", line_num);
            if ((line = get_next_line(fd1)) != NULL)
            {
                printf("test1 >>> %s", line);
                free(line);
                finished = 0;
            }
            if ((line = get_next_line(fd2)) != NULL)
            {
                printf("test2 >>> %s", line);
                free(line);
                finished = 0;
            }
            if ((line = get_next_line(fd3)) != NULL)
            {
                printf("test3 >>> %s", line);
                free(line);
                finished = 0;
            }
            line_num++;
        }
        close(fd1);
        close(fd2);
        close(fd3);
    }
    else
    {
        // Abrir os arquivos
        fd1 = open("test1.txt", O_RDONLY);
        fd2 = open("test2.txt", O_RDONLY);
        fd3 = open("test3.txt", O_RDONLY);

        if (fd1 < 0 || fd2 < 0 || fd3 < 0)
        {
            perror("Erro ao abrir arquivos");
            return (1);
        }

        // Ler e imprimir as linhas do arquivo test1.txt
        printf("\n--- Conteudo de test1.txt ---\n");
        line_num = 1;
        while ((line = get_next_line(fd1)) != NULL)
        {
            printf("test1 >>>>> line %d: %s", line_num++, line);
            free(line);
        }
        close(fd1);

        // Ler e imprimir as linhas do arquivo test2.txt
        printf("\n--- Conteudo de test2.txt ---\n");
        line_num = 1;
        while ((line = get_next_line(fd2)) != NULL)
        {
            printf("test2 >>>>> line %d: %s", line_num++, line);
            free(line);
        }
        close(fd2);

        // Ler e imprimir as linhas do arquivo test3.txt
        printf("\n--- Conteudo de test3.txt ---\n");
        line_num = 1;
        while ((line = get_next_line(fd3)) != NULL)
        {
            printf("test3 >>>>> line %d: %s", line_num++, line);
            free(line);
        }
        close(fd3);
    }

    return (0);
}


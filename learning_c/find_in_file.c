/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 23:38:38 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/15 23:39:01 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void  str(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int  find(char *name, char *file)
{
	int	i = 0;
	int	j = 0;
	int len = 0;
	int	count = 0;

	len = strlen(name);
	while (file[i])
	{
		if (file[i] == name[j])
		{
			while (file[i] == name[j])
			{
				j++;
				i++;
				if (j == len)
					count = count + 1;
			}
			j = 0;
		}
		i++;
	}
	return (count);
}

int  main(int ac, char **av)
{
	int		fd;
	int		readint;
	char	*name;
	char	*string;
	int		acc;

	if (ac < 4)
	{
		str("Usage :\n");
		str("	./name [Your_word] [Buffer] [File] [Other_file] ...\n");
		return (0);
	}

	int		BUFF_SIZE = atoi(av[2]);
	char	buffer[BUFF_SIZE + 1];
	name = strdup(av[1]);
	acc = ac;
	ac = 4;
	while (ac <= acc)
	{
		fd = open(av[ac - 1], O_RDONLY);
		readint = read(fd, buffer, BUFF_SIZE);
		if (readint == -1)
		{
			str("Error : read fail\n");
			return (-1);
		}
		str(av[ac - 1]);
		str(":\n");
		if (find(name, buffer) > 0)
		{
			str("\033[1;32;40m	I found '");
			str(name);
			printf("' %d time(s)\033[0m\n", find(name, buffer));
		}
		else
			str("\033[1;31;40m	Wrong... I didn't find sorry...!\033[0m\n");
		ac++;
	}
	return (0);
}

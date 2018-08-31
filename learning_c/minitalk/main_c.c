/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:26:17 by ppellegr          #+#    #+#             */
/*   Updated: 2018/05/15 19:38:14 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			*ft_conv_dec_bin(int c)
{
	int			*b;
	int			i;
	int			k;

	b = (int*)malloc(sizeof(int) * 8);
	k = 0;
	while (k < 8)
		b[k++] = 0;
	i = 0;
	while (c >= 1)
	{
		b[i++] = c % 2;
		c = c / 2;
	}
	return (b);
}

void		ft_send(int pid, int *b)
{
	int			i;

	i = 0;
	while (i < 8)
	{
		if (b[i] == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("Killing Error", 2);
				exit(0);
			}
		}
		if (b[i] == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("Killing Error", 2);
				exit(0);
			}
		}
		usleep(150);
		i++;
	}
}

void		ft_transcript(int pid, char *s)
{
	int			i;
	int			*b;

	i = 0;
	while (s[i] != '\0')
	{
		b = ft_conv_dec_bin((int)s[i]);
		ft_send(pid, b);
		i++;
	}
	b = ft_conv_dec_bin((int)'\0');
	ft_send(pid, b);
}

int			main(int argc, char **argv)
{
	char *s;

	s = NULL;
	if (argc == 2)
	{
		while (ft_get_next_line(0, &s))
		{
			ft_transcript(ft_atoi(argv[1]), s);
			free(s);
		}
	}
	else
		ft_putendl_fd("usage : [PID] [string]", 2);
	return (0);
}

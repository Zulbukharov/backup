/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:26:13 by ppellegr          #+#    #+#             */
/*   Updated: 2018/05/15 19:31:06 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int			*b;

int				ft_conv_bin_dec(int *b)
{
	int			i;
	int			p;
	int			res;

	i = 0;
	p = 0;
	res = 0;
	while (i < 8)
	{
		res = b[i] * ft_power(i) + res;
		i++;
		p++;
	}
	return (res);
}

void			ft_interpret(int s)
{
	printf("%d\n", s);
	if (s == SIGUSR1)
		*b++ = 0;
	else if (s == SIGUSR2)
		*b++ = 1;
}

void			ft_aff_pid(void)
{
	int			pid;

	pid = getpid();
	ft_putendl("Server started");
	ft_putnbr(pid);
	ft_putendl("");
}

char			*ft_binary(char *str, int *tmp)
{
	static int			buf = 0;

	if (buf > 510)
		str = ft_realloc(str, BUF);
	str[buf++] = (char)ft_conv_bin_dec(tmp);
	if ((char)ft_conv_bin_dec(tmp) == '\0')
	{
		ft_putendl(str);
		buf = 0;
	}
	b = tmp;
	ft_bzero(b, 8);
	return (str);
}

int				main(void)
{
	int			i;
	int			*tmp;
	char		*str;

	i = 0;
	b = (int*)(malloc(sizeof(int) * 8));
	str = (char*)malloc(sizeof(char) * BUF);
	ft_bzero(b, 8);
	tmp = b;
	ft_aff_pid();
	while (1)
	{
		if (signal(SIGUSR1, ft_interpret) == SIG_ERR)
			ft_putendl_fd("Fail !", 2);
		if (signal(SIGUSR2, ft_interpret) == SIG_ERR)
			ft_putendl_fd("Fail !", 2);
		if (i > 7)
		{
			str = ft_binary(str, tmp);
			i = 0;
		}
		pause();
		i++;
	}
	return (0);
}

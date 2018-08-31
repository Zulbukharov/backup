/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_text_without_printf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:36:20 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/16 21:49:57 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *a)
{
	write(1, "\033[1;32m", 8);
	write(1, a, ft_strlen(a));
	write(1, "\n", 1);
	write(1, "\033[1;34m", 8);
	write(1, a, ft_strlen(a));
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	ft_putstr(av[1]);
	return (0);
}

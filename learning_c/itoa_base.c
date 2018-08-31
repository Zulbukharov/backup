/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:22:08 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/16 21:33:40 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *s)
{
	int nbr;
	int neg;

	neg = 1;
	nbr = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			neg = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		nbr = nbr * 10 + *s - 48;
		s++;
	}
	return (nbr * neg);
}

int		ft_pow(int base, int n)
{
	if (n == 0)
		return (1);
	return (base * ft_pow(base, n - 1)); 
}

char	*ft_itoa_base(int value, int base)
{
	char *s;
	int neg;
	int i;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	s = (char *)malloc(sizeof(char) * i);
	s[i + neg] = '\0';
	while (i-- > 0)
	{
		s[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

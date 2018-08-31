/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:19:13 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/16 21:50:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int		main(int ac, char **av)
{
	unsigned int num1;
	unsigned int sum;
	unsigned int num2;

	num1 = 122;
	num2 = 121;

	printf("num1: %s => %d\n", ft_itoa_base(num1, 2), num1);
	printf("num2: %s => %d\n", ft_itoa_base(num2, 2), num2);
	sum = num1 ^ num2;
	printf("sum:  %s => %d\n", ft_itoa_base(sum, 2), sum);


	return (0);
}

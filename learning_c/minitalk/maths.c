/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 03:13:19 by ppellegr          #+#    #+#             */
/*   Updated: 2014/02/08 03:13:20 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_power(int i)
{
	int			p;

	p = 1;
	while (i > 0)
	{
		p = p * 2;
		i--;
	}
	return (p);
}

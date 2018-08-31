/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 20:15:31 by ppellegr          #+#    #+#             */
/*   Updated: 2014/02/09 20:15:33 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char			*ft_realloc(char *s, int size)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + size));
	ft_strcpy(tmp, s);
	if (s != NULL)
		free(s);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:41:23 by ppellegr          #+#    #+#             */
/*   Updated: 2018/05/15 19:36:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUF 1024

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	char		r[BUF + 1];
	int			size;
}				t_node;

int				ft_power(int i);
char			*ft_realloc(char *s, int size);
int				ft_get_next_line(const int fd, char **line);

#endif /* !MINITALK_H */

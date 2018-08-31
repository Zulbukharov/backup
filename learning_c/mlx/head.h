/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:27:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/27 18:43:14 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <stdlib.h>

typedef struct 	s_config
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			w;
	int			h;
	int			*filed;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_config;

#endif

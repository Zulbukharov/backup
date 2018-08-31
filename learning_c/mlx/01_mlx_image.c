/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:17:54 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/27 19:01:30 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "head.h"

int		main(void)
{
	t_config *cfg;
	long int i;

	i = 12500;

	cfg = (t_config*)malloc(sizeof(t_config));
	cfg->w = 1200;
	cfg->h = 900;
	cfg->mlx_ptr = mlx_init();
	cfg->win_ptr = mlx_new_window(cfg->mlx_ptr, cfg->w, cfg->h, "MARSHALL");
	cfg->img_ptr = mlx_new_image(cfg->mlx_ptr, cfg->w, cfg->h);
	cfg->filed = (int*)mlx_get_data_addr(cfg->img_ptr, &cfg->bits_per_pixel, &cfg->size_line, &cfg->endian);
	while (i < 100000)
	{
		cfg->filed[i] = 0xFF0000;
		printf("\033[32;1mbits_per_pixel: %d, size_line: %d, endian %d\n", cfg->bits_per_pixel, cfg->size_line, cfg->endian);
		/* bits_per_pixel количетсов бит, выделяемое под пиксель
		 */
		i++;
	}
	mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img_ptr, 0, 0);
	mlx_loop(cfg->mlx_ptr);
	return (0);	
}

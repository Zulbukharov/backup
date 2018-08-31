/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:38:25 by azulbukh          #+#    #+#             */
/*   Updated: 2018/05/01 09:43:48 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h> 
#include <stdio.h>  
#include <math.h> 
#include "mlx.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define X 800
#define Y 600
#define CENTERX 400
#define CENTERY 300

typedef struct  s_config
{
  void    *mlx_ptr;
  void    *img_ptr;
  void    *win_ptr;
  double     w;
  double     h;
  int     *filed;
  int     bits_per_pixel;
  int     size_line;
  int     endian;
  double  zoom;
  double  x;
  double  y;
  int     miny;
  int     maxy;
  double  curx; // movex
  double  cury; //  movey
  double  curq;// zoom
  double minRe;
  double maxRe;
  double  minIm;
  double  maxIm;
}       t_config;



static void        put_pixel(double x, double y, t_config *data, long int color)
{
    int i;

    if ((x >= 0 && x < 800) && (y >= 0 && y < 600))
    {
        i = (int)x + ((int)y * (data->size_line / 4));
        data->filed[i] = color;
    }
}

void barnsleyFern(int windowWidth, unsigned long iter, t_config *cfg){
 
	double x0=0,y0=0,x1,y1;
	int diceThrow;
	time_t t;
	srand((unsigned)time(&t));
 
	while(iter>0){
		diceThrow = rand()%100;
 
		if(diceThrow==0){
			x1 = 0;
			y1 = 0.16*y0;
		}
 
		else if(diceThrow>=1 && diceThrow<=7){
			x1 = -0.15*x0 + 0.28*y0;
			y1 = 0.26*x0 + 0.24*y0 + 0.44;
		}
 
		else if(diceThrow>=8 && diceThrow<=15){
			x1 = 0.2*x0 - 0.26*y0;
			y1 = 0.23*x0 + 0.22*y0 + 1.6;
		}
 
		else{
			x1 = 0.85*x0 + 0.04*y0;
			y1 = -0.04*x0 + 0.85*y0 + 1.6;
		}
 
		put_pixel(30*x1 + windowWidth/2.0, 30*y1, cfg, 0X00A86B);
 
		x0 = x1;
		y0 = y1;
 
		iter--;
	}
 
}

int   main(void)
{
  t_config *cfg;

  cfg = (t_config*)malloc(sizeof(t_config));
  cfg->w = 800;
  cfg->h = 600;
  cfg->mlx_ptr = mlx_init();
  cfg->win_ptr = mlx_new_window(cfg->mlx_ptr, cfg->w, cfg->h, "MARSHALL");
  cfg->img_ptr = mlx_new_image(cfg->mlx_ptr, cfg->w, cfg->h);
  cfg->filed = (int*)mlx_get_data_addr(cfg->img_ptr, &cfg->bits_per_pixel, &cfg->size_line, &cfg->endian);
  cfg->curq = 1;
  cfg->curx = -0.5;
  cfg->cury = 0;
  cfg->minRe = -2;
  cfg->minRe = -2.0;
  cfg->maxRe = 1.0;
  cfg->minIm = -1.2;
  cfg->maxIm = cfg->minIm+(cfg->maxRe-cfg->minRe)*Y/X;

//   draw(cfg, cfg->curq, cfg->curx, cfg->cury);
barnsleyFern(X, 10000, cfg);
  mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img_ptr, 0, 0);
//   mlx_hook(cfg->win_ptr, 4, 0, mouse_win1, cfg);
  // mlx_hook(cfg->win_ptr, 5, 1L<<6, deal_mouse, cfg);
//   mlx_hook(cfg->win_ptr, 2, 5, deal_key, cfg);
  mlx_loop(cfg->mlx_ptr);
  return (0); 
}

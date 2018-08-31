#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <SDL2/SDL.h>

#define	WINDOW_W 640
#define WINDOW_H 480

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_col;

typedef	struct		s_sphere
{
	t_vec			center;
	int				radius;
	t_col			color;
}					t_sphere;

typedef	struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	t_vec			camera;
	double			viewport_size;
	double			projection_plane_z;
}					t_env;

double	dot_product(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	substract(t_vec v1, t_vec v2)
{
	t_vec new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

void	exit_fail(const char *error, int num)
{
	printf("[%s][%d]\n", error, num);
	exit(0);
}

void	init(t_env *env)
{
	if ((SDL_Init(SDL_INIT_EVERYTHING) == -1))
		exit_fail(SDL_GetError(), 1);
	if ((SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &env->window, &env->renderer) == -1))
		exit_fail(SDL_GetError(), 2);
	//if (SDL_SetRenderDrawColor(env->renderer, 255, 0, 0, 255) < 0)
	//	exit_fail(SDL_GetError(), 3);
	env->camera.x = 0;
	env->camera.y = 0;
	env->camera.z = 0;
	env->viewport_size = 1;
	env->projection_plane_z = 1;
}

void	draw_rect(t_env env)
{

	SDL_Rect	rect;
	rect.x = 10;
	rect.y = 10;
	rect.h = 50;
	rect.w = 50;
	if ((SDL_RenderFillRect(env.renderer, &rect) < 0))
		exit_fail(SDL_GetError(), 4);
}

void	draw_line(t_env env)
{
	if (SDL_RenderDrawLine(env.renderer, 10, 10, 100, 100) < 0)
		exit_fail(SDL_GetError(), 5);
}

void	destroy(t_env env)
{
	SDL_DestroyRenderer(env.renderer);
	SDL_DestroyWindow(env.window);
	SDL_Quit();
	printf("[DONE]\n");
}

void	intersect_ray(t_vec origin, t_vec diraction, t_sphere sphere, t_vec *ts)
{
	t_vec oc = substract(origin, sphere.center);
	double k1 = dot_product(diraction, diraction);
	double k2 = 2 * dot_product(oc, diraction);
	double k3 = dot_product(oc, oc) - sphere.radius * sphere.radius;

	double diskriminant = k2 * k2 - 4 * k1 * k3;
	if (diskriminant < 0)
	{
		ts->x = SDL_MAX_UINT32;
		ts->y = SDL_MAX_UINT32;
		return ;
	}
	ts->x = (-k2 + sqrt(diskriminant)) / (2 * k1);
	ts->y = (-k2 - sqrt(diskriminant)) / (2 * k1);
}

void	trace_ray(t_vec camera, t_vec diraction, t_col *color)
{
	int closest = SDL_MAX_UINT32;
	t_sphere *closest_sphere = NULL;
	int	i;
	t_vec ts;
	t_sphere	spheres[3] = 
	{
		{{0, -1, 3}, 1, {255, 0, 0, 255}},
		{{2, 0, 4}, 1, {0, 0, 255, 255}},
		{{-2, 0, 4}, 1, {0, 255, 0, 255}},
	};

	i = -1;
	while (++i < 3)
	{
		intersect_ray(camera, diraction, spheres[i], &ts);
		if (ts.x < closest && 1 < ts.x && ts.x < SDL_MAX_UINT32)
		{
			closest = ts.x;
			closest_sphere = &spheres[i];
		}
		if (ts.y < closest && 1 < ts.y && ts.y < SDL_MAX_UINT32)
		{
			closest = ts.y;
			closest_sphere = &spheres[i];
		}
	}
	if (!(closest_sphere))
	{
		color->r = 255;
		color->g = 255;
		color->b = 255;
		color->a = 255;
	}
	else
	{
		*color = closest_sphere->color;
		//printf("[not black]\n");
	}
}

void	put_pixel(int x, int y, t_col color, t_env env)
{
	// printf("[%d][%d][%d]\n", color.r, color.g, color.b);
	x = WINDOW_W / 2 + x;
	y = WINDOW_H / 2 + y;
	SDL_SetRenderDrawColor(env.renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawPoint(env.renderer, x, y);
}

void	draw_sphere(t_env env)
{
	t_vec	xy;
	t_vec	diraction;
	t_col	color;

	xy.x = -(WINDOW_W / 2);
	while (xy.x < WINDOW_W / 2)
	{
		xy.y = -(WINDOW_H / 2);
		while (xy.y < WINDOW_H / 2)
		{
			diraction.x = xy.x * env.viewport_size / WINDOW_W;
			diraction.y = xy.y * env.viewport_size / WINDOW_W;
			diraction.z = env.projection_plane_z;
			// trace ray
			int closest = SDL_MAX_UINT32;
			t_sphere *closest_sphere = NULL;
			int	i;
			t_vec ts;
			t_sphere	spheres[3] = 
			{
				{{0, -1, 3}, 1, {255, 0, 0, 255}},
				{{0, 0, 0}, 1, {0, 0, 255, 255}},
				{{-2, 0, 4}, 1, {0, 255, 0, 255}},
			};
			i = 0;
			while (i < 3)
			{
				t_vec oc = substract(env.camera, spheres[i].center);
				double k1 = dot_product(diraction, diraction);
				double k2 = 2 * dot_product(oc, diraction);
				double k3 = dot_product(oc, oc) - spheres[i].radius * spheres[i].radius;

				double diskriminant = k2 * k2 - 4 * k1 * k3;
				if (diskriminant < 0)
				{
					ts.x = SDL_MAX_UINT32;
					ts.y = SDL_MAX_UINT32;
				}
				else
				{
					ts.x = (-k2 + sqrt(diskriminant)) / (2 * k1);
					ts.y = (-k2 - sqrt(diskriminant)) / (2 * k1);
				}
				// intersect_ray(env.camera, diraction, spheres[i], &ts);
				if (ts.x < closest && 1 < ts.x && ts.x < SDL_MAX_UINT32)
				{
					closest = ts.x;
					closest_sphere = &spheres[i];
				}
				if (ts.y < closest && 1 < ts.y && ts.y < SDL_MAX_UINT32)
				{
					closest = ts.y;
					closest_sphere = &spheres[i];
				}
				i++;
			}
			if (!(closest_sphere))
			{
				color.r = 255;
				color.g = 255;
				color.b = 255;
				color.a = 255;
			}
			else
			{
				color = closest_sphere->color;
				//printf("[not black]\n");
			}
			put_pixel(xy.x, xy.y, color, env);
			xy.y++;
		}
		xy.x++;
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	int		q;

	q = 0;
	init(&env);
	// draw_line(env);
	// draw_rect(env);
	draw_sphere(env);
	SDL_RenderPresent(env.renderer);
	while (!q)
		while(SDL_PollEvent(&env.e))
			env.e.type == SDL_QUIT ? q = 1 : 0;
	destroy(env);
	return (0);
}
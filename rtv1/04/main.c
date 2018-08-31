#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>

#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				b_w;
	int				b_h;
}					t_env;

typedef	struct		s_tex
{
	SDL_Texture		*background;
	SDL_Texture		*image;
}					t_tex;

void	apply_surface(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer)
{
	SDL_Rect	pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos);
}

SDL_Texture		*load_image(char *file, t_env *env)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	surface = NULL;
	texture = NULL;
	if ((surface = SDL_LoadBMP(file)))
	{
		texture = SDL_CreateTextureFromSurface(env->renderer, surface);
		SDL_FreeSurface(surface);
	}
	else
		printf("[%s]\n", SDL_GetError());
	return (texture);
}

void	destroy(t_env env, t_tex tex)
{
	SDL_DestroyTexture(tex.background);
	SDL_DestroyTexture(tex.image);
	SDL_DestroyRenderer(env.renderer);
	SDL_DestroyWindow(env.window);
	printf("[Done]\n");
}

int		main(int ac, char **av)
{
	t_env	env;
	t_tex	tex;

	if ((SDL_Init(SDL_INIT_EVERYTHING) == -1))
		printf("[%s]\n", SDL_GetError());
	if (!(env.window = SDL_CreateWindow("simple", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)))
		printf("[%s]\n", SDL_GetError());
	if (!(env.renderer = SDL_CreateRenderer(env.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		printf("[%s]\n", SDL_GetError());
	if (!(tex.background = load_image("background.bmp", &env)) || !(tex.image = load_image("image.bmp", &env)))
		printf("[%s]\n", SDL_GetError());
	SDL_RenderClear(env.renderer);
	SDL_QueryTexture(tex.background, NULL, NULL, &env.b_w, &env.b_h);
	apply_surface(0, 0, tex.background, env.renderer);
	apply_surface(env.b_w, 0, tex.background, env.renderer);
	apply_surface(0, env.b_h, tex.background, env.renderer);
	apply_surface(env.b_w, env.b_h, tex.background, env.renderer);
	SDL_RenderPresent(env.renderer);
	SDL_Delay(3000);
	destroy(env, tex);
	return (0);
}
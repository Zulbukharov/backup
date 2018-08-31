#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

int	main(int ac, char **av)
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Surface		*bmp;

	window = NULL;
	render = NULL;
	surface = NULL;
	texture = NULL;
	bmp = NULL;
	// инициализация подсистем SDL => аудио, таймер, видео, клава
	if (SDL_Init(SDL_INIT_EVERYTHING))
		printf("[%s]\n", SDL_GetError());
	// Создание окна [тайтл, позиция, размер, флаги]
	if (!(window = SDL_CreateWindow("SDL RTv1", 0, 0, 640, 480, SDL_WINDOW_SHOWN)))
		printf("[%s]\n", SDL_GetError());
	// Создание Рендера [окно, индекс драйвера, флаги]
	if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC)))
		printf("[%s]\n", SDL_GetError());
	// Загрузка BMP изоброжения
	if (!(bmp = SDL_LoadBMP("03/hello.bmp")))
		printf("[%s]\n", SDL_GetError());
	// Загрузка изобожения в рендерер
	if (!(texture = SDL_CreateTextureFromSurface(render, bmp)))
		printf("[%s]\n", SDL_GetError());
	SDL_FreeSurface(bmp);
	SDL_RenderClear(render);
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderPresent(render);
	SDL_Delay(5000);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
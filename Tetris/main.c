#include "Tetris.h"
#include "SDL.h"
#include <stdio.h>

typedef enum {
	SQUARE_WIDTH = 20,
	SQUARE_HEIGHT = 20,
} SquareSize;

typedef enum {
	SCREEN_WIDTH = SQUARE_WIDTH * TETRIS_TABLE_WIDTH,
	SCREEN_HEIGHT = SQUARE_HEIGHT * TETRIS_TABLE_HEIGHT,
} ScreenSize;

void PrintBits(uint16_t *table)
{
	printf("------\n");
	for (int i = 0; i < TETRIS_TABLE_HEIGHT; ++i)
	{
		unsigned mask = 0x8000;
		for (int j = 0; j < TETRIS_TABLE_WIDTH; ++j)
		{
			printf("%d", (table[i] & mask) ? 1 : 0);
			mask >>= 1;
		}
		printf("\n");
	}
}

void Redraw(Tetris_Game *game, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	for (int y = 0; y < TETRIS_TABLE_HEIGHT; ++y)
	{
		int row = game->table[y];
		for (int x = 0; x < TETRIS_TABLE_WIDTH; ++x)
		{
			if (row & 0x8000)
			{
				SDL_Rect rect = {
					.x = x * SQUARE_WIDTH,
					.y = y * SQUARE_HEIGHT,
					.w = SQUARE_WIDTH,
					.h = SQUARE_HEIGHT,
				};
				SDL_RenderFillRect(renderer, &rect);
			}
			row <<= 1;
		}
	}

	SDL_RenderPresent(renderer);
}

void MainLoop(Tetris_Game *game, SDL_Renderer *renderer)
{
	PrintBits(game->table);

	SDL_Event ev;

	while (1)
	{
		Redraw(game, renderer);

		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
				return;

			if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_LEFT:
					Tetris_MovePlayerLeft(game);
					PrintBits(game->table);
					break;
				case SDLK_RIGHT:
					Tetris_MovePlayerRight(game);
					PrintBits(game->table);
					break;
				case SDLK_SPACE:
					Tetris_RotatePlayer(game);
					PrintBits(game->table);
					break;
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	
	Tetris_Game tetrisGame;
	Tetris_ResetGame(&tetrisGame, Tetris_GetRandomUnit());
	tetrisGame.table[1] |= 0x0802;
	MainLoop(&tetrisGame, renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
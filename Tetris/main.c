#include "Tetris.h"
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SQUARE_WIDTH = 20,
    SQUARE_HEIGHT = 20,
} SquareSize;

typedef enum {
    SCREEN_WIDTH = SQUARE_WIDTH * TETRIS_TABLE_WIDTH,
    SCREEN_HEIGHT = SQUARE_HEIGHT * TETRIS_TABLE_HEIGHT,
} ScreenSize;

typedef enum {
    DEFAULT_UPDATE_PERIOD = 1000,
    FAST_UPDATE_PERIOD = 50,
} UpdatePeriod;

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

uint32_t GetUpdatePeriod(void)
{
    const uint8_t *keyboard = SDL_GetKeyboardState(NULL);
    return (keyboard[SDL_SCANCODE_DOWN]) ? FAST_UPDATE_PERIOD : DEFAULT_UPDATE_PERIOD;
}

void MainLoop(Tetris_Game *game, SDL_Renderer *renderer)
{
    PrintBits(game->table);

    SDL_Event ev;
    uint32_t lastUpdate = SDL_GetTicks();

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
                case SDLK_RETURN:
                case SDLK_SPACE:
                case SDLK_y:
                case SDLK_z:
                    Tetris_RotatePlayer(game);
                    PrintBits(game->table);
                    break;
                }
            }
        }

        uint32_t now = SDL_GetTicks();

        if (now - lastUpdate < GetUpdatePeriod())
            continue;

        lastUpdate = now;
        uint8_t status = Tetris_UpdateGame(game);
        if (status == TETRIS_PLAYER_SCORED)
        {
            printf("SCORED %d", game->currentScore);
        }
        else if (status == TETRIS_GAME_OVER)
        {
            printf("GAME OVER \n\n%d\n", game->currentScore);
            return;
        }
        printf("\n\n%d\n", game->currentScore);
        PrintBits(game->table);
    }
}

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    Tetris_Game tetrisGame;
    Tetris_ResetGame(&tetrisGame, Tetris_GetUnit('T'));
    MainLoop(&tetrisGame, renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
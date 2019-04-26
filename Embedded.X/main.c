#include "../Tetris/Tetris.h"

#include <xc.h>

void main(void)
{
    Tetris_Game game;
    Tetris_ResetGame(&game, Tetris_GetRandomUnit());
    Tetris_MovePlayerLeft(&game);
    Tetris_RotatePlayer(&game);
}

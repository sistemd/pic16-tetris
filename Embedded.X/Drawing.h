#pragma once

#include "Tetris.h"

extern void DrawTetris(Tetris_Game *tetrisGame);

extern void DrawCurrentScore(Tetris_Game *tetrisGame);

extern void DrawHighscore(uint16_t highscore);

extern void FlashVictoriously(void);

#pragma once

#include <stdint.h>

enum
{
	TETRIS_MAX_ROTATIONS = 4,
};

typedef enum {
	TETRIS_TABLE_WIDTH = 16,
	TETRIS_TABLE_HEIGHT = 32,
} Tetris_TableSize;

typedef enum
{
	TETRIS_UNIT_HEIGHT = 4,
} Tetris_UnitSize;

typedef struct {
	uint8_t x;
	uint8_t y;
} Position;

typedef struct {
	uint8_t numRotations;
	uint16_t bits[TETRIS_UNIT_HEIGHT][TETRIS_MAX_ROTATIONS];
} Tetris_Unit;

typedef struct {
	Position position;
	const Tetris_Unit *unit;
	uint16_t unitBits[TETRIS_UNIT_HEIGHT];
	uint8_t rotation;
} Tetris_Player;
/*
  unitBits is kept in sync with position.x and allows for
  easier and faster environment overlap checking.
*/

typedef struct {
	uint16_t table[TETRIS_TABLE_HEIGHT];
	Tetris_Player player;
	uint16_t currentScore;
} Tetris_Game;

typedef enum {
	TETRIS_GAME_OVER,
	TETRIS_GAME_CONTINUES,
} Tetris_GameState;

extern const Tetris_Unit *Tetris_GetRandomUnit(void);

extern const Tetris_Unit *Tetris_GetUnit(char designator);

extern void Tetris_ResetGame(Tetris_Game *game, const Tetris_Unit *playerUnit);

extern Tetris_GameState Tetris_UpdateGame(Tetris_Game *game);

/*
  Tetris_MovePlayerDown and Tetris_ClearFilledRows are mostly
  exposed to be testable and are not really useful as part of the interface.
*/
extern uint8_t Tetris_ClearFilledRows(uint16_t *gameTable);

extern uint8_t Tetris_MovePlayerDown(Tetris_Game *game);

extern void Tetris_MovePlayerLeft(Tetris_Game *game);

extern void Tetris_MovePlayerRight(Tetris_Game *game);

extern void Tetris_RotatePlayer(Tetris_Game *game);

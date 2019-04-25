#include "Tetris.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

enum
{
	TETRIS_NUM_UNITS = 2,
};

static Position const Tetris_unitPivot = {
	.x = 3,
	.y = 2,
};

static Position const Tetris_playerStartingPosition = {
	.x = 8,
	.y = 2,
};

static Tetris_Unit const Tetris_units[TETRIS_NUM_UNITS] = {
	{
		.numRotations = 2,
		.bits = {
			{
				0b00010000,
				0b00010000,
				0b00010000,
				0b00010000,
			},
			{
				0b00000000,
				0b00000000,
				0b00111100,
				0b00000000,
			},
		},
	},
	{
		.numRotations = 1,
		.bits = {
			{
				0b00000000,
				0b00011000,
				0b00011000,
				0b00000000,
			},
		},
	},
};

static uint8_t Tetris_PlayerTopmostY(Tetris_Player *player)
{
	return player->position.y - Tetris_unitPivot.y;
}

static uint8_t Tetris_PlayerOverlapsEnvironment(Tetris_Game *game)
{
	uint8_t start = Tetris_PlayerTopmostY(&game->player);
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		if (game->player.unitBits[i] & game->table[i + start])
			return 1;
	}

	return 0;
}

static uint8_t Tetris_PlayerTouchingLeftBound(Tetris_Player *player)
{
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		if (player->unitBits[i] & 0x8000)
			return 1;
	}

	return 0;
}

static uint8_t Tetris_PlayerTouchingRightBound(Tetris_Player *player)
{
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		if (player->unitBits[i] & 0x0001)
			return 1;
	}

	return 0;
}

static void Tetris_RemovePlayerFromTable(Tetris_Game *game)
{
	uint8_t start = Tetris_PlayerTopmostY(&game->player);
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		game->table[start + i] &= ~game->player.unitBits[i];
	}
}

static void Tetris_ApplyPlayerToTable(Tetris_Game *game)
{
	uint8_t start = Tetris_PlayerTopmostY(&game->player);
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		game->table[start + i] |= game->player.unitBits[i];
	}
}

static void Tetris_SetPlayerUnit(Tetris_Player *player, const Tetris_Unit *unit)
{
	uint8_t shift = Tetris_playerStartingPosition.x - Tetris_unitPivot.x;
	player->unit = unit;
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		player->unitBits[i] = player->unit->bits[0][i];
		player->unitBits[i] <<= 8 - shift;
	}
}

static void Tetris_ResetPlayer(Tetris_Player *player, const Tetris_Unit *playerUnit)
{
	player->position = Tetris_playerStartingPosition;
	player->rotation = 0;
	Tetris_SetPlayerUnit(player, playerUnit);
}

const Tetris_Unit *Tetris_GetRandomUnit(void)
{
	// FIXME The rand is biased because I use %
	return Tetris_units + (rand() % TETRIS_NUM_UNITS);
}

const Tetris_Unit *Tetris_GetUnit(char designator)
{
	switch (designator)
	{
	case 'I': return Tetris_units + 0;
	case 'O': return Tetris_units + 1;
	}

	return NULL;
}

void Tetris_ResetGame(Tetris_Game *game, const Tetris_Unit *playerUnit)
{
	memset(game, 0, sizeof *game);
	Tetris_ResetPlayer(&game->player, playerUnit);
	Tetris_ApplyPlayerToTable(game);
}

void Tetris_Update(Tetris_Game *game)
{

}

void Tetris_MovePlayerLeft(Tetris_Game *game)
{
	if (Tetris_PlayerTouchingLeftBound(&game->player))
		return;

	Tetris_RemovePlayerFromTable(game);

	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
		game->player.unitBits[i] <<= 1;

	if (Tetris_PlayerOverlapsEnvironment(game))
	{
		for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
			game->player.unitBits[i] >>= 1;
	}
	else
	{
		--game->player.position.x;
	}

	Tetris_ApplyPlayerToTable(game);
}

void Tetris_MovePlayerRight(Tetris_Game *game)
{
	if (Tetris_PlayerTouchingRightBound(&game->player))
		return;

	Tetris_RemovePlayerFromTable(game);

	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
		game->player.unitBits[i] >>= 1;

	if (Tetris_PlayerOverlapsEnvironment(game))
	{
		for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
			game->player.unitBits[i] <<= 1;
	}
	else
	{
		++game->player.position.x;
	}

	Tetris_ApplyPlayerToTable(game);
}

void Tetris_RotatePlayer(Tetris_Game *game)
{
	Tetris_RemovePlayerFromTable(game);
	++game->player.rotation;
	game->player.rotation %= game->player.unit->numRotations;
	Tetris_ApplyPlayerToTable(game);
}

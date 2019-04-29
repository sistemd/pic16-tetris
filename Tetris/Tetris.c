#include "Tetris.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

enum
{
	TETRIS_NUM_UNITS = 7,
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
		.designator = 'I',
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
		.designator = 'O',
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
	{
		.designator = 'T',
		.numRotations = 4,
		.bits = {
			{
				0b00000000,
				0b00010000,
				0b00111000,
				0b00000000,
			},
			{
				0b00000000,
				0b00010000,
				0b00011000,
				0b00010000,
			},
			{
				0b00000000,
				0b00000000,
				0b00111000,
				0b00010000,
			},
			{
				0b00000000,
				0b00010000,
				0b00110000,
				0b00010000,
			},
		},
	},
	{
		.designator = 'L',
		.numRotations = 4,
		.bits = {
			{
				0b00000000,
				0b00010000,
				0b00010000,
				0b00011000,
			},
			{
				0b00000000,
				0b00001000,
				0b00111000,
				0b00000000,
			},
			{
				0b00000000,
				0b00110000,
				0b00010000,
				0b00010000,
			},
			{
				0b00000000,
				0b00000000,
				0b00111000,
				0b00100000,
			},
		},
	},
	{
		.designator = 'J',
		.numRotations = 4,
		.bits = {
			{
				0b00000000,
				0b00010000,
				0b00010000,
				0b00110000,
			},
			{
				0b00000000,
				0b00100000,
				0b00111000,
				0b00000000,
			},
			{
				0b00000000,
				0b00011000,
				0b00010000,
				0b00010000,
			},
			{
				0b00000000,
				0b00100000,
				0b00111000,
				0b00000000,
			},
		},
	},
	{
		.designator = 'S',
		.numRotations = 2,
		.bits = {
			{
				0b00000000,
				0b00011000,
				0b00110000,
				0b00000000,
			},
			{
				0b00000000,
				0b00010000,
				0b00011000,
				0b00001000,
			},
		},
	},
	{
		.designator = 'Z',
		.numRotations = 2,
		.bits = {
			{
				0b00000000,
				0b00110000,
				0b00011000,
				0b00000000,
			},
			{
				0b00000000,
				0b00001000,
				0b00011000,
				0b00010000,
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

static uint8_t Tetris_ApplyPlayerToTable(Tetris_Game *game)
{
	uint8_t start = Tetris_PlayerTopmostY(&game->player);

	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		if (game->player.unitBits[i] == 0)
			continue;

		if (start + i >= TETRIS_TABLE_HEIGHT)
			return 0;
	}

	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
		game->table[start + i] |= game->player.unitBits[i];

	return 1;
}

static uint8_t Tetris_CountUnitBits(const uint16_t *unitBits)
{
	uint8_t result = 0;
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		uint16_t mask = 1;
		for (uint8_t j = 0; j < TETRIS_TABLE_WIDTH; ++j)
		{
			if (unitBits[i] & mask)
				++result;
			mask <<= 1;
		}
	}
	return result;
}

static void Tetris_UpdatePlayerUnitBits(Tetris_Player *player)
{
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
		player->unitBits[i] = player->unit->bits[player->rotation][i];

	int8_t shift = 8 - player->position.x + Tetris_unitPivot.x;

	if (shift > 0)
	{
		for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
			player->unitBits[i] <<= shift;
	}
	else
	{
		shift = -shift;
		for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
			player->unitBits[i] >>= shift;
	}
}

static uint8_t Tetris_PlayerUnitBitsAreValid(const Tetris_Player *player)
{
	return Tetris_CountUnitBits(player->unit->bits[player->rotation]) == Tetris_CountUnitBits(player->unitBits);
}

static void Tetris_SetPlayerUnit(Tetris_Player *player, const Tetris_Unit *unit)
{
	player->unit = unit;
	Tetris_UpdatePlayerUnitBits(player);
}

static void Tetris_ResetPlayer(Tetris_Player *player, const Tetris_Unit *playerUnit)
{
	player->position = Tetris_playerStartingPosition;
	player->rotation = 0;
	Tetris_SetPlayerUnit(player, playerUnit);
}

static void Tetris_ShiftTableDown(uint16_t *gameTable, uint8_t upto)
{
	uint8_t i;

	for (i = upto; i != 0; --i)
	{
		if (gameTable[i] == 0)
			break;
		gameTable[i] = gameTable[i - 1];
	}

	gameTable[i] = 0;
}

static uint8_t Tetris_ScoreForRowsCleared(uint8_t rowsCleared)
{
	switch (rowsCleared)
	{
	case 0:  return 0;
	case 1:  return 1;
	case 2:  return 3;
	case 3:  return 5;
	default: return 7;
	}
}

const Tetris_Unit *Tetris_GetRandomUnit(void)
{
	return Tetris_units + (rand() % TETRIS_NUM_UNITS);
}

const Tetris_Unit *Tetris_GetUnit(char designator)
{
	for (const Tetris_Unit *i = Tetris_units; i != Tetris_units + TETRIS_NUM_UNITS; ++i)
	{
		if (i->designator == designator)
			return i;
	}

	return NULL;
}

void Tetris_ResetGame(Tetris_Game *game, const Tetris_Unit *playerUnit)
{
	memset(game, 0, sizeof *game);
	Tetris_ResetPlayer(&game->player, playerUnit);
	Tetris_ApplyPlayerToTable(game);
}

Tetris_GameState Tetris_UpdateGame(Tetris_Game *game)
{
	if (!Tetris_MovePlayerDown(game))
	{
		uint8_t rowsCleared = Tetris_ClearFilledRows(game->table);
		game->currentScore += Tetris_ScoreForRowsCleared(rowsCleared);

		Tetris_ResetPlayer(&game->player, Tetris_GetRandomUnit());
		if (Tetris_PlayerOverlapsEnvironment(game))
			return TETRIS_GAME_OVER;
		Tetris_ApplyPlayerToTable(game);
	}

	return TETRIS_GAME_CONTINUES;
}

uint8_t Tetris_ClearFilledRows(uint16_t *gameTable)
{
	uint8_t rowsCleared = 0;

	for (uint8_t i = 0; i < TETRIS_TABLE_HEIGHT;)
	{
		if (gameTable[i] == 0xFFFF)
		{
			Tetris_ShiftTableDown(gameTable, i);
			++rowsCleared;
		}
		else
		{
			++i;
		}
	}

	return rowsCleared;
}

uint8_t Tetris_MovePlayerDown(Tetris_Game *game)
{
	Tetris_RemovePlayerFromTable(game);
	++game->player.position.y;

	if (Tetris_PlayerOverlapsEnvironment(game) || !Tetris_ApplyPlayerToTable(game))
	{
		--game->player.position.y;
		Tetris_ApplyPlayerToTable(game);
		return 0;
	}

	return 1;
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

	uint8_t oldRotation = game->player.rotation;
	++game->player.rotation;
	game->player.rotation %= game->player.unit->numRotations;
	Tetris_UpdatePlayerUnitBits(&game->player);
	if (!Tetris_PlayerUnitBitsAreValid(&game->player) || Tetris_PlayerOverlapsEnvironment(game))
	{
		game->player.rotation = oldRotation;
		Tetris_UpdatePlayerUnitBits(&game->player);
	}

	Tetris_ApplyPlayerToTable(game);
}

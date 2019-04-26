#include "Tetris.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

enum
{
	TETRIS_NUM_UNITS = 3,
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
	{
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

static uint8_t Tetris_CountUnitBits(const uint16_t *unitBits)
{
	uint8_t result = 0;
	for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
	{
		uint16_t mask = 1;
		for (uint8_t j = 0; j < 16; ++j)
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
	case 'T': return Tetris_units + 2;
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

uint8_t Tetris_MovePlayerDown(Tetris_Game *game)
{
	Tetris_RemovePlayerFromTable(game);
	++game->player.position.y;
	if (Tetris_PlayerOverlapsEnvironment(game))
	{
		--game->player.position.y;
		Tetris_ApplyPlayerToTable(game);
		return 0;
	}
	Tetris_ApplyPlayerToTable(game);
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
